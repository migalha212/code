% 1 incognita, 2 known
plus(X,Y,Z):- number(X), number(Y), Z is X + Y.
plus(X,Y,Z):- number(X), number(Z), Y is Z - X.
plus(X,Y,Z):- number(Y), number(Z), X is Z - Y.

% in this case, if N is an already instantiated value, we can call 
% a more efficient lenght function, if it is not, we call the normal tail recursive

my_length(L, N):-
    number(N),
    N >= 0,
    my_length_1(L,N).
my_length(L,N):-
    var(N),
    my_length_2(L,N).

my_length_1([], 0).
my_length_1([_|T], N):-
    N1 is N - 1
    my_length_1(T,N).

my_length_2([],0).
my_length_2([_|T], N):-
    my_length_2(T,N1),
    N is N1 + 1.



get_tree_a(node(3,node(1,null,null),node(7,node(5,null,null),node(9,null,null)))).

double(X,Y):-
    Y is 2*X.

tree_map(_,null,null).
tree_map(F,node(X,Left,Right),node(Y,NewLeft,NewRight)):-
    Goal =.. (F,X,Y),
    call(Goal),
    tree_map(F,Left,NewLeft),
    tree_map(F,Right,NewRight).