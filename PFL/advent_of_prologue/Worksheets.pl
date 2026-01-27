% Worksheet 2 

% Recursion

% factorial(+N, -F)
factorial(0,1):- !.
factorial(N,F):-
    N1 is N - 1,
    factorial(N1, F1),
    F is F1 * N.

% sum_rec(+N, -Sum) 
sum_rec(1,1):- !.
sum_rec(N,Sum):-
    N1 is N - 1,
    sum_rec(N1,Sum1),
    Sum is Sum1 + N.

% pow_rec(+X, +Y, -P)
pow_rec(_,0,1):- !.
pow_rec(X,Y,P):-
    Y1 is Y - 1,
    pow_rec(X,Y1,P1),
    P is X * P1.

% square_rec(+N, -S)
square_rec(N,S):-
    square_rec_aux(N,N,0,S).

square_rec_aux(_,0,Acc,Acc):-!.
square_rec_aux(N,R,Acc,S):-
    Acc1 is Acc + N,
    R1 is R - 1,
    square_rec_aux(N,R1,Acc1,S).

% fibonacci(+N, -F)
fibonacci(0,1):-!.
fibonacci(1,1):-!.
fibonacci(N,F):-
    N1 is N -1,
    N2 is N - 2,
    fibonacci(N1,F1),
    fibonacci(N2,F2),
    F is F1 + F2.

% collatz(+N, -S),
collatz(1,0):-!.
collatz(N,S):-
    0 is N mod 2,
    N1 is N div 2,
    collatz(N1, S1),
    S is S1 + 1.
collatz(N,S):-
    1 is N mod 2,
    N1 is 3 * N + 1,
    collatz(N1, S1),
    S is S1 + 1.

% is_prime(+X)
is_prime(1).
is_prime(X):-
    X > 1,
    \+ has_divisor(X, 2).

has_divisor(X, N):-
    N * N =< X,
    0 is X mod N.
has_divisor(X, N):-
    N * N < X,
    N1 is N + 1,
    has_divisor(X, N1).


%flight(origin, destination, company, code, hour, duration)
flight(porto, lisbon, tap, tp1949, 1615, 60).
flight(lisbon, madrid, tap, tp1018, 1805, 75).
flight(lisbon, paris, tap, tp440, 1810, 150).
flight(lisbon, london, tap, tp1366, 1955, 165).
flight(london, lisbon, tap, tp1361, 1630, 160).
flight(porto, madrid, iberia, ib3095, 1640, 80).
flight(madrid, porto, iberia, ib3094, 1545, 80).
flight(madrid, lisbon, iberia, ib3106, 1945, 80).
flight(madrid, paris, iberia, ib3444, 1640, 125).
flight(madrid, london, iberia, ib3166, 1550, 145).
flight(london, madrid, iberia, ib3163, 1030, 140).
flight(porto, frankfurt, lufthansa, lh1177, 1230, 165).

:- use_module(library(lists)).

% get_all_nodes(-ListOfAirports)
get_all_nodes(L):-
    findall(Node, (flight(Node,_,_,_,_,_) ; flight(_,Node,_,_,_,_)),List),
    sort(List,L).

% most_diversified(-Company)
most_diversified(Company):-
    setof(C, (A,B,D,E,F)^flight(A,B,C,D,E,F), Companies),
    findall(Count-C1, (
        member(C1,Companies),
        findall(D, flight(D,_,C1,_,_,_), Flights),
        length(Flights,Count)
    ),
    Pairs),
    max_member(MaxCount-_, Pairs),
    member(MaxCount-Company, Pairs).

% find_flights(+Origin, +Destination, -Flights)
find_flights(O,D,F):-
    find_flights_aux(O,D,[], Flights),
    reverse(Flights,F).
find_flights_aux(O,D,Acc,[Code|Acc]):-
    flight(O,D,_,Code,_,_),
    \+ member(Code, Acc).
find_flights_aux(O,D,Acc,Flights):-
    flight(O,Intermediary,_,Code,_,_),
    \+ member(Code,Acc),
    find_flights_aux(Intermediary,D,[Code|Acc],Flights).

% find_flights_bfs(+Origin, +Destination, -Flights)
find_flights_bfs(O,D,F):-
    find_flights_bfs_aux([[O,[]]],D,[O],F).

find_flights_bfs_aux([[F,Codes]|_],F,_,Codes).
find_flights_bfs_aux([[City,Codes]|R],F,Visited, Res):-
    findall([Next,[Code|Codes]],
    (
    flight(City,Next,_,Code,_,_),
    \+ member(Next,Visited)
    ),
    NR),
    findall(C, member([C,_],NR),NewC),
    append(Visited,NewC,UVisited),
    append(R,NR,UR),
    find_flights_bfs_aux(UR,F,UVisited,Res).

% find_all_flights (+Origin, +Destination, -ListOfFlights)
find_all_flights(O,D,L):-
    findall(Route,find_flights(O,D,Route),L).

% find_flights_least_stops(+Origin, +Destination, -ListOfFlights)
find_flights_least_stops(O,D,L):-
    find_flights_bfs(O,D,R),
    length(R,MinL),
    findall(Route, (find_flights_bfs(O,D,Route), length(Route,MinL)),L).

% find_flights_stops(+Origin, +Destination, +Stops, -ListFlights)
find_flights_stop(O,D,[],L):-
    find_flights(O,D,L).
find_flights_stop(O,D,[Stop|Rest],L):-
    find_flights(O,Stop,L1),
    find_flights_stop(Stop,D,Rest,L2),
    append(L1,L2,L).

% find_circular_trip (+MaxSize, +Origin, -Cycle)
