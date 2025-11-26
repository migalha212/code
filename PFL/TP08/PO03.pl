list_size([], 0).
list_size([_|[]], 1).
list_size([_|B], Size):-
    list_size(B, Size2),
    Size is Size2 + 1.

list_sum([], 0).
list_sum([A], A).
list_sum([A|B], Sum):-
    list_sum(B,Sum2),
    Sum is A + Sum2.

list_prod([], 0).
list_prod([A], A).
list_prod([A|B], P):-
    list_prod(B,P2),
    P is A * P2.

inner_product([], _, 0).
inner_product(_, [], 0).
inner_product([A],[B],A*B).
inner_product([A|B],[C|D], Prod):-
    inner_product(B,D,Prod2),
    Prod is (A * C) + Prod2.

count(_,[],0).
count(A,[A|T],C):-
    count(A,T,C2),
    C is C2 + 1.
count(A,[H|T],C):-
    A \== H,
    count(A,T,C).

% invert(+List1, ?List2)    
invert([],[]).
invert([A],[A]).
invert([H|T],L):-
    invert(T,L1),
    append(L1,[H],L).

rev(L,R):-
    revAcc(L,[],R).

revAcc([],Acc,Acc).
revAcc([H|T],Acc,R):-
    revAcc(T,[H|Acc],R).



% del_one(+Elem, +List1, ?List2)
del_one(_,[],[]).
del_one(A,[A],[]).
del_one(A,[A|T],L):-
    L is [T].
del_one(A,[H|T],L):-
    A \== H,
    del_one(A,T,L).

% class(Course, ClassType, DayOfWeek, Time, Duration)

% TPC !!!!!

% 4 d) Implement list_nth(?N, ?List, ?Elem), which unifies Elem with the Nth element of List, 
% using only the append and length predicates.
% length(List,4).
% append([a,b], [c], X)  X gets the result C is appended to a b

% list_nth(?N, ?List, ?Elem)
list_nth(N, L, Elem):-
    append(Prefix, [Elem |_Suffix], L),     % Attempt to define a prefix and sufix
    length(Prefix, N).  % Check if the lenght matches

list_nth_recur(0, [H| _], H).
list_nth_recur(N, [_|T], X):-
    N1 is N - 1,
    list_nth_recur(N1, T, X).


% 4 g) Implement list_before(?First, ?Second, ?List), which succeeds if the first two arguments are 
% members of List, and First occurs before Second, using only the append predicate twice. 

% list_before(?First, ?Second, ?List)
% list_before(First, Second, List):-
    append(_A, [First | Rem], List), % Attempt to find the first element in the list
    append(_B, [Second | _C ], Rem). % attempt to find the second element in the remainder

list_before_rec(X,Y [X|T]):-
    member(Y,T).
list_before_rec(X,Y,[_|T]):-
    list_before(X,Y,T).

list_replace_one_rec(X,Y[X|T],[Y|T]).
list_replace_one_rec(x,Y,[H|T],[H|T2]):-
    list_replace_one_rec(X,Y,T,T2).

my_max(L,X):-
    member(X,L),
    \+ ((
        member(Y,L),
        Y > x
    )).

% Classes predicate
% class(Course, ClassType, DayOfWeek, Time, Duration)

class(pfl,  t,  '2 Tue', 15,   2).
class(pfl,  tp, '2 Tue', 10.5, 2).

class(law,  t,  '3 Wed', 10.5, 2).
class(law,  tp, '3 Wed',  8.5, 2).

class(ipc,  t,  '4 Thu', 14.5, 1.5).
class(ipc,  tp, '4 Thu', 16,   1.5).

class(fsi,  t,  '1 Mon', 10.5, 2).
class(fsi,  tp, '5 Fri',  8.5, 2).

class(rc,   t,  '5 Fri', 10.5, 2).
class(rc,   tp, '1 Mon',  8.5, 2).


% 3 b)

daily_courses(Day, Courses) :-
    setof(Course,(Type,Time,Duration) ^ class(Course, Type, Day, Time, Duration), Courses).


% 3 e)

courses(L) :-
    setof(Course,(Type,Day,Time,Duration)^class(Course, Type, Day, Time, Duration), L).