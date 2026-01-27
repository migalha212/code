/*
Consider a knowledge made up of children (child/3 predicate), who made a wishlist of toys for this Christmas.
Each child as a home city. The toys in the wish list are ordered in decreasing order of preference.

Each toy has a price, given by the toy/2 predicate.

The santa_list/2 predicate indicates, for each month whether each child was nice or naughty.

The edge/2 predicate indicates which pairs of cities are closeby (they form an undirected, disconnected graph).
*/

% child(ChildName,Wishlist,CityName)
child(asdrubal,['Nintendo Switch','RC car'],porto).
child(bruno,['Teddy bear','Nintendo Switch'],coimbra).
child(clara,['Xylophone','Water gun'],porto).
child(daniel,['Teddy bear'],gondomar).
child(elsa,['Teddy bear'],lisbon).
child(frank,['RC car', 'Xylophone'],braga).
child(sofia,['RC car','Teddy bear','Dart board'],sofia).

:- dynamic toy/2.

% toy(ToyName,Price)
toy('Nintendo Switch',250).
toy('RC car',35).
toy('Teddy bear',15).
toy('Xylophone',28).
toy('Water gun',30).
toy('Dart board',12).

% santa_list(Month,[Child-NiceOrNaughty])
santa_list(january,[asdrubal-nice,bruno-naughty,clara-nice,daniel-naughty,elsa-nice,frank-naughty,sofia-nice]).
santa_list(february,[asdrubal-nice,bruno-nice,clara-nice,daniel-naughty,elsa-nice,frank-nice,sofia-nice]).
santa_list(march,[asdrubal-nice,bruno-nice,clara-nice,daniel-naughty,elsa-nice,frank-nice,sofia-nice]).
santa_list(april,[asdrubal-nice,bruno-naughty,clara-naughty,daniel-naughty,elsa-nice,frank-nice,sofia-nice]).
% ...

% edge(City1,City2)
edge(porto,gondomar).
edge(braga,porto).
edge(coimbra,lisbon).


% Day 0

% Implement cheap_toy(?ToyName), which succeeds if ToyName exists and costs less or equal than 20€.

% first unify into Vthe price of the toy, then compare
cheap_toy(ToyName):-
    toy(ToyName, V),
    V =< 20.

% Day 1

% Implement same_name_as_city(?Child), which suceeds if the child named Child has the same name as their hometown.

same_name_as_city(Child):-
    children(Child, _,Child).

% Day 2

% Implement n_wishes(?Child,?N), which succeeds if Child has exactly N items in their wishlist.

n_wishes(Child,N):-
    children(Child, L, _),
    length(L,N).

% Day 3

% Implement was_naughty(?Month,?Child), which succeeds if Child was naughty during month Month.

was_naughty(Month,Child):-
    santa_list(Month, L),
    member(L , Child-naughty).

% Day 4

% Implement count_n_naughty(?Month,?N), which succeeds if there where exactly N naughty children in month Month

count_n_naughty(Month,N):-
    santa_list(Month,L),
    count_aux(L,0,N).

count_aux([],Acc,Acc).
count_aux([_-naughty|T],Acc,N):-
    Acc1 is Acc + 1,
    count_aux(T,Acc1,N).
count_aux([_-nice|T],Acc,N):-
    count_aux(T,Acc,N).

% Day 5

% Implement most_expensive_toy(?Toy), which succeeds if Toy is the toy with the highest price (or each of the toys with the highest price, in case of a tie).

most_expensive_toy(Toy):-
    toy(Toy,V),
    \+ (toy(_,V2),
    V2 > V).

% Day 6

% Implement common_toys(?Child1,?Child2,?Toys), which succeeds if Toys is a list of all the toys common in the wishlists of Child1 and Child2.

common_toys(Child1,Child2,Toys):-
    children(Child1,WL1),
    children(Child2,WL2),
    common_aux(WL1,WL2,Toys).

common_aux([],_,[]).
common_aux([H|T], WL2, [H|T2]):-
    member(H,WL2),
    !,
    common_aux(T,WL2,T2).
common_aux([_|T],WL2,T2):-
    common_aux(T,WL2,T2).

% Day 7

% Implement was_naughty_twice(+Child), which succeeds if Child was naughty in at least two different months.

was_naughty(Child):-
    was_naughty(M1,Child),
    was_naughty(M2,Child),
    M1 \= M2,
    !.

% Day 8

% Implement wants_more(?Child,?Toy1,?Toy2), which succeeds if Child wants Toy1 more than Toy2 for Christmas (i.e. Toy1 comes before Toy2 in Child's wishlist)'

wants_more(Child,T1,T2):-
    children(Child,WL),
    append(_, [T1|Suf], WL),
    append(_, [T2|_],Suf).

% Day 9

% Implement second_most_demanding_child(?Child), which suceeds if Child is one of the children with the second highest number of toys in the wishlist.

second_most_demanding_child(Child):-
    most_demanding_child(_,Max),
    !, % the cut is used to avoid redundant solutions when there is more than one most demanding child
    n_wishes(Child,N),
    N < Max,
    \+((
        n_wishes(_,N1),
        N1 > N,
        N1 < Max
    )).

most_demanding_child(Child,N):-
    n_wishes(Child,N),
    \+((
        n_wishes(_,N1),
        N1 > N
    )).

% Day 10

% Implement set_toy_price(+Toy,+Price), which updates the knowledge base with the new Price for Toy.

set_toy_price(Toy, Price):-
    retract(toy(Toy,_)), 
    !,
    assert(toy(Toy,Price)).

% Day 11

% Implement print_santa_list(?Month), which prints the names of all the children, followed by whether they were naughty or not in month Month, in separate lines.

print_santa_list(Month):-
    santa_list(Month,L),
    format("Month: ~w~n", [Month]),
    print_list_aux(L).

print_list_aux([Child-Status|T]):-
    format("~w was ~w~n", [Child,Status]),
    print_list_aux(T).
print_list_aux(_).

% Day 12

% Implement update_naughty_list(+Month,+Child,+WasNaughty), which updates Santa´s naughty list on the knowledge base for a given month and child by changing the indication of whether they were naughty or not.

update_naughty_list(Month,Child,WasNaughty):-
    santa_list(Month, L),
    append(Prefix,[Child-_| Suffix], L),
    append(Prefix,[Child-WasNaughty | Suffix], Updated),
    retract(santa_list(Month,_)),
    assert(santa_list(Month,Updated)).

% Day 13

% Implement toy_children_list(?Toy,?ChildList), which succeeds if ChildList is a list with all the children who have Toy in their wishlist.


toy_children_list(Toy,ChildList) :-
	toy_children_list_aux(Toy,[],ChildList).

toy_children_list_aux(Toy, KidList, FinalKidList) :-
	child(New_kid, Whishlist, _),
	member(Toy, Whishlist),
	\+(member(New_kid, KidList)), !,
	toy_children_list_aux(Toy, [New_kid | KidList], FinalKidList).

toy_children_list_aux(_, Acc, Acc).

% Day 14

% Implement wanted_by_all(?Toy), which succeeds if Toy is the name of a toy wanted by all the children.
% Option C

wanted_by_all(Toy):-
    children(_,W),
    member(Toy, W),
    \+ (
        children(_,WL),
        \+ member(Toy,WL)
    ).

:- use_module(library(lists)).

% Day 15

% Implement toy_even_price_list(?L), which unifies L with a list of pairs Toy-Price, for all the toys with a price that is an even number 

toy_even_price_list(L):-
    findall(Toy,
            (toy(Toy,Price),
            0 is Price mod 2
            ),
            L).

% Day 16

% Implement city_children(?City,?Children), which unifies Children with the list of children from City.

city_children(City,Children):-
    bagof(Child,(L)^child(Child,L,City), Children).

% Day 17

% Implement get_unique_cities(?Cities), which unifies Cities with a list of all the cities the children live in (without duplicates).

get_unique_cities(Cities):-
    findall(City, child(_,_,City), All),
    sort(All,Cities).

% Day 18

% Implement average_toy_price(?Avg), which unifies Avg with the average toy price.

average_toy_price(Avg):-
    findall(Price,toy(_,Price),All),
    sumlist(All, Sum),
    length(All, N),
    Avg is Sum / N.

% Day 19

% Implement most_common_toy_per_city(?City,?Toy), which suceeds if Toy is the most common toy in the wish list of the children from city.

most_common_toy_per_city(City, Toy):-
    findall(T, (child(_,Toys,City), member(T,Toys)), Toys),
    findall(
        Count-T1,
        (
            member(T1,Toys),
            findall(T2, (member(T2, Toys), T2 = T1), Occurrences),
            length(Occurrences,Count)
        ),
        Pairs
    ),
    sort(Pairs,Unique),
    last(Unique,_-Toy).

% Day 20

% Implement print_toys(?ToyPrintFunc), which prints, in separate lines, each toy using the supplied binary I/O predicate ToyPrintFunc, which receives a toy´s name and price.

print_toys(ToyPrintFunc):-
    findall(Toy-Price,toy(Toy,Price),Toys),
    print_toys_aux(ToyPrintFunc,Toys).

print_toys_aux(_,[]).
print_toys_aux(ToyPrintFunc,[Toy-Price|T]):-
    G =.. [ToyPrintFunc,Toy,Price],
    call(G),
    print_toys_aux(ToyPrintFunc, T).

print_toy_info(Toy, Price) :-
    format('~w costs ~d~n', [Toy, Price]).

% Day 21

% Implement classify_children(?TestChildFunc,?FilteredChildren), which suceeds if FilteredChildren is a list of all the knowledge´s children, where the children that satisfy TestChildFunc (prefix of yes´s) are placed before the children that do not satisfy it (suffix of no´s).
% The order of the children in the yes´s and no´s sublist must match their order in the knowledge base.
% TestChildFunc is a function to a 3-argument predicate that receives, in order, the child´s name, wishlist and home city.
% You cannot call append/3 or re-define it.

classify_children(TestChildFunc, FilteredChildren):-
    findall(yes-Child,(child(Child,WL,City), G =.. [TestChildFunc, Child, WL, City], call(G)),YesChildren),
    findall(Child-no,(child(Child,WL,City), G1 =.. [TestChildFunc, Child, WL, City], \+ call(G1)),NoChildren),
    append([YesChildren,NoChildren], FilteredChildren).

classify_children_with_aux(TestChildFunc, FilteredChildren):-
    findall(Child,(child(Child,WL,City), G =.. [TestChildFunc, Child, WL, City], call(G)),YesChildren),
    findall(Child,(child(Child,WL,City), G1 =.. [TestChildFunc, Child, WL, City], \+ call(G1)),NoChildren),
    append_difference_list(YesChildren\NoChildren, NoChildren\[], FilteredChildren\[]).

append_difference_list(A\B, B\C, A\C).



has_many_toys(Child, WL, City) :-
    length(WL, N),
    N > 3.

from_lisbon(Child, WL, City) :-
    City = lisbon.
