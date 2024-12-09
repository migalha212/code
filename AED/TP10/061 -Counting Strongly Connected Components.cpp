//! for full implementation of graph and function in practice check TP10/graph.h

#include <iostream>
#include "graph.h"

int main() {

    // Number of graphs to test
    int n;
    std::cin >> n;

    // For each graph: read, call the method and delete graph at the end
    for (int i = 1; i <= n; i++) {
        Graph* g = Graph::readGraph();
        std::cout << "Graph #" << i << ": countSCCs() = " << g->countSCCs() << std::endl;
        delete g;
    }

    return 0;
}

/*
int countSCCs() {
        int order = 1;
        int count = 0;
        std::stack<int> s;
        for (int i = 1; i <= n; i++) { nodes[i].visited = false; nodes[i].order = 0; }
        for (int i = 1; i <= n; i++) {
            if (nodes[i].order == 0) {
                dfs61(i, order, s, count);
            }
        }
        return count;
    }

    void dfs61(int v, int& order, std::stack<int>& s, int& count) {
        nodes[v].order = order;
        nodes[v].lowest = order++;
        s.push(v);
        nodes[v].visited = true;
        for (Edge e : nodes[v].adj) {
            int w = e.dest;
            if (nodes[w].order == 0) {
                dfs61(w, order, s, count);
                nodes[v].lowest = std::min(nodes[v].lowest, nodes[w].lowest);
            }
            else if (nodes[w].visited)
                nodes[v].lowest = std::min(nodes[v].lowest, nodes[w].lowest);
        }
        if (nodes[v].order == nodes[v].lowest) {
            count++;
            int n = -1;
            while (!s.empty() && n != v) {
                n = s.top();
                nodes[n].visited = false;
                s.pop();
            }
        }
    }
*/