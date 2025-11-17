% these are the facts, marked by statements, as if its a database

%%% a
male(frank).
male(jay).
male(javier).
male(merle).
male(phil).
male(mitchell).
male(cameron). % Example of a homosexual relationship. This affects how we define siblings!
male(joe).
male(manny).
male(bo).
male(dylan).
male(luke).
male(rexford).
male(calhoun).
male(george).

female(grace).
female(dede).
female(gloria).
female(barb).
female(claire).
female(pameron).
female(haley).
female(alex).
female(lily).
female(poppy).

parent(grace,phil).
parent(frank,phil).

parent(dede,claire).
parent(jay,claire).
parent(dede,mitchell).
parent(jay,mitchell).

parent(jay,joe).
parent(gloria,joe).

parent(gloria,manny).
parent(javier,manny).

parent(barb,cameron).
parent(merle,cameron).
parent(barb,pameron).
parent(merle,pameron).

parent(phil,haley).
parent(claire,haley).
parent(phil,alex).
parent(claire,alex).
parent(phil,luke).
parent(claire,luke).

parent(mitchell,lily).
parent(cameron,lily).
parent(mitchell,rexford).
parent(cameron,rexford).

parent(pameron,calhoun).
parent(bo,calhoun).

parent(dylan,george).
parent(dylan,poppy).
parent(haley,george).
parent(haley,poppy).

married(jay,gloria,2008).
married(jay,dede,1968).

divorced(jay,dede,2003).


% is a rule, :- marks a rule,  ',' is a logical and
father(X,Y):-
    male(X),
    parent(X,Y).

mother(X,Y):-
    female(X),
    parent(X,Y).

grandparent(X,Y):-
    parent(X,Z),
    parent(Z,Y).

grandmother(X,Y):-
    female(X),
    grandparent(X,Y).

grandfather(X,Y):-
    male(X),
    grandparent(X,Y).

siblings(X,Y):-
    parent(P1,X),
    parent(P1,Y),
    parent(P2,X),
    parent(P2,Y),
    P1@<P2,
    X\=Y.

halfSiblings(X,Y):-
    parent(P,X),
    parent(P,Y),
    \+siblings(X,Y), % \+ not operator
    X\=Y.

cousins(X,Y):-
    parent(P1,X),
    parent(P2,Y),
    siblings(P1,P2),
    \+siblings(X,Y),
    P1@<P2.

uncle(X,Y):-
    parent(Z,Y),
    siblings(X,Z).

areMarried(X,Y,Year):-
    married(X,Y,Year1),
    Year1 =< Year,
    \+divorced(X,Y,_).

areMarried(X,Y,Year):-
    married(X,Y,Year1),
    Year1 =< Year,
    divorced(X,Y,Year2),
    Year2 >= Year.

