%flight(origin,destination,company,code,hour,duration)
flight(porto,lisbon,tap,tp1949,1615,60).
flight(lisbon,madrid,tap,tp1018,1805,75).
flight(lisbon,london,tap,tp1366,1955,165).

direct_flight(O,D,Code) :-
    flight(O,D,_,Code,_,_).

source_or_dest(N) :-
    direct_flight(N,_,_).
source_or_dest(N):-
    direct_flight(_,N,_).

get_all_nodes(L):-
    findall(N,source_or_dest(N),Nodes).
    sort(Nodes,L). % to remove duplicates


find_flights_dfs(Ni,Nf,Fs) :-
    dfs([Ni], Nf, Fs).

dfs([N|_],N,[]).
dfs([Nc|T], Nf, [F|FS]) :-
    direct_flight(Nc, Nb, F),
    \+member(Nb, [Nc|T]),
    dfs([Nb,Nc|T],nf, Fs).

:- use_module(library(lists)).

find_flights_bfs(Ni,Nf,Fs):-
    get_all_nodes(Ns),
    member(Ni,Ns),
    bfs([[Ni]-[]], Nf, Le),
    reverse(Le,Fs).

bfs([[Nf|_]-Fs|_], Nf, Fs).
bfs([[N1|T]-Fs|Ns], Nf, Sol):-
    findall([Nb,Na|T]-[F|Fs],
            (direct_flight(Na,Nb,F),
            \+member(Nb,[Na|T])),
            Ns1),
    append(Ns, Ns1, Ns2),
    bfs(NS2,Nf,Sol).

