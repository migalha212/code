:-dynamic by/3.

% by(Character, Movie, Actor)
by(jackRyan, theSumOfAllFears, benAffleck).
by(cathyMuller, theSumOfAllFears, bridgetMoynahan).
by(jackRyan, theHuntForRedOctober, alecBaldwin).
by(jackRyan, patriotGames, harrisonFord).
by(cathyMuller, patriotGames, anneArcher).
by(jackRyan, clearAndPresentDanger, harrisonFord).
by(cathyMuller, clearAndPresentDanger, anneArcher).
by(president, airForceOne, harrisonFord).
by(frasierCrane, cheers, kelseyGrammer).
by(frasierCrane, frasier, kelseyGrammer).
by(rachelGreen, friends, jenniferAniston).
by(monicaGeller, friends, courteneyCox).
by(phoebeBuffay, friends, lisaKudrow).
by(ursulaBuffay, friends, lisaKudrow).
by(joeyTribbiani, friends, mattLeBlanc).
by(joeyTribbiani, joey, mattLeBlanc).
by(alexGarrett, joey, andreaAnders).
by(stephenColbert, dailyShow, stephenColbert).
by(stephenColbert, theColbertReport, stephenColbert).
by(addisonMontgomery, privatePractice, kateWalsh).
by(addisonMontgomery, greysAnatomy, kateWalsh).
by(mattMurdock, daredevil, benAffleck).
by(elektraNatchios, daredevil, jenniferGarner).
by(elektraNatchios, elektra, jenniferGarner).
by(elektraNatchios, elektra, lauraWard).
by(sydneyBristow, alias, jenniferGarner).


% plays_twins(?Actor, ?Movie)
play_twins(Actor,Movie):-
    by(C,Movie,Actor),
    by(C2,Movie,Actor),
    C \= C2.

% actor_movies(+Actor, -Movies)
actor_movies(Actor,Movies):-
    actor_movies(Actor,[], Movies).
actor_movies(Actor,Acc,Movies):-
    by(_,Movie,Actor),
    \+ member(Movie,Acc), !,
    actor_movies(Actor,[Movie|Acc],Movies).
actor_movies(_,Acc,Acc).
% Getting a list of all elements without find all, requires an auxiliary method, that goes through all hipotesis adding them to an accumulator, returning only when no more options are available and passing the accumulator to the result

% changeSelf/0
changeSelf:-
    retract(by(Actor,M,Actor)),
    assert(by(self,M,Actor)),
    fail.
changeSelf.
% this line is here so the predicate has a way to always succeed once, be it due to no more actors to change, or just none to change
% using by with _ _ _ could be viable, but just this line by itself implies it will just succeed with no further discussion or context

% playedBy(+Character, -List)

playedBy(Character,List):-
    findall(Actor-L,setof(Movie,by(Character,Movie,Actor),L),List).

playedBy(Character, List):-
    setof(Actor, Movie^by(Character, Movie, Actor), Actors),
    findall(A-Ms, ( member(A, Actors), findall(M, by(Character, M, A), Ms) ), List).

:- use_module(library(lists)).

% most_popular(+Exclude, -List, -NMovies)

most_popular(E,L,NM):-
    setof(Actor,(C,M)^(by(C,M,Actor), \+ member(Actor,E)),Actors),
    findall(N-A, (member(A,Actors), setof(Ms, C^by(C,Ms,A), Acted), length(Acted,N)),Pairs),
    max_member(NM-_,Pairs),
    findall(A1, member(NM-A1,Pairs), L).
% when trying to get the counts, its important to either sort or use setof so that, if an Actor did more than one character in a movie it doesnt appear twice, thus giving them a higher count than intended
most_popular(Exclude, List, NMovies):-
    setof(N-Actor, (_Char,_Movie,_Movies)^(
        by(_Char, _Movie, Actor), \+ member(Actor, Exclude),
        actor_movies(Actor, _Movies), length(_Movies, N) ), TempL),
    last(TempL, NMovies-_),
    findall(Actor, member(NMovies-Actor, TempL), List).

% connection_link(+Actor1, +Actor2, -ConnectionList)

% A - M - A 
connection_link(A1,A2,C):-
    connection_aux(A1, A2, [A1], RL),
    reverse(RL,C).

% direct
connection_aux(C,D, Acc, [D,M | Acc]):-
    by(_,M,C),
    \+ member(M, Acc),
    by(_,M,D),
    D \= C.
% not direct
connection_aux(C,D,Acc,Rl):-
    by(_,M,C),
    \+ member(M,Acc),
    by(_,M,Md),
    Md \= C,
    \+ member(Md,Acc),
    connection_aux(Md,D,[Md,M|Acc],Rl).

% pretty_print(+ConnectionList)

pretty_print([A1,M,A2|Rest]):-
    write(A1), write(' worked in '), write(M), write(' with '), write(A2),
    pretty_print_aux(Rest).

pretty_print_aux([]):-
    write('.').
pretty_print_aux([M,A | Rest]):-
    write(','),nl,
    write(' who worked in '), write(M), write(' with '), write(A),
    pretty_print_aux(Rest).
