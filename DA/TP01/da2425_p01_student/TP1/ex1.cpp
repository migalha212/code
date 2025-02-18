#include <iostream>
#include "../data_structures/Graph.h"

using namespace std;

/****************** DFS ********************/
/*
 * Performs a depth-first search (dfs) in a graph from the source node.
 * Returns a vector with the contents of the vertices by dfs order.
 */
template<class T>
vector<T> dfs(Graph<T> *g, const T &source) {
    vector<int> res;
    vector<Vertex<T> *> v = g->getVertexSet();
    if (v == nullptr) return res;

    for (auto vertex: g->getVertexSet()) {
        vertex->setVisited(false);
    }

    for (auto vertex : g->getVertexSet()) {
        dfsVisit(vertex,res);
    }
    return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Updates a parameter with the list of visited node contents.
 */
template<class T>
void dfsVisit(Vertex<T> *v, vector<T> &res) {
    if (!v->visited) {
        res.push_back(v);
        v->setVisited(true);
        for (auto edge : v->adj) {
            Vertex<T> w = edge->dest;
            if (!w->visited)
                dfsVisit(w,res);
        }
    }
}

/****************** BFS ********************/
/*
 * Performs a breadth-first search (bfs) in a graph, starting
 * from the vertex with the given source contents (source).
 * Returns a vector with the contents of the vertices by bfs order.
 */
template<typename T>
vector<T> bfs(Graph<T> *g, const T &source) {
    vector<int> res;
    // TODO
    return res;
}
