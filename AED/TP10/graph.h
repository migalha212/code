// -------------------------------------------------------------
// Algorithms and Data Structures 2024/2025 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2425/
// -------------------------------------------------------------
// A simple lightweight graph class
// Last update: 24/11/2024
// -------------------------------------------------------------

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>

class Graph
{
    struct Edge
    {
        int dest;   // Destination node 
        int weight; // An integer weight
    };

    struct Node
    {
        std::list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;        // Has the node been visited in a graph traversal?
        int dist = 0;
        int order = 0;
        int lowest;
    };

    int n;                   // Graph size (vertices are numbered from 1 to n)
    bool hasDir;             // false: undirected; true: directed
    std::vector<Node> nodes; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int num, bool dir = false) : n(num), hasDir(dir), nodes(num + 1) {}

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1) {
        if (src<1 || src>n || dest<1 || dest>n) return;
        nodes[src].adj.push_back({ dest, weight });
        if (!hasDir) nodes[dest].adj.push_back({ src, weight });
    }

    // --------------------------------------------------------------

    // Read a graph in the format:
    // nr_nodes directed/undirected weighted/unweighted
    // nr_edges
    // src_1 dest_1 <weight_1>
    // src_2 dest_2 <weight_2>
    // ...
    // src_n dest_n <weight_n>
    static Graph* readGraph() {
        int n;
        std::string sdirection, sweight;
        std::cin >> n >> sdirection >> sweight;
        bool directed = (sdirection == "directed") ? true : false;
        bool weighted = (sweight == "weighted") ? true : false;

        Graph* g = new Graph(n, directed);
        int e;
        std::cin >> e;
        for (int i = 0; i < e; i++) {
            int u, v, w = 1;
            std::cin >> u >> v;
            if (weighted) std::cin >> w;
            g->addEdge(u, v, w);
        }
        return g;
    }

    // --------------------------------------------------------------
    // Depth-First Search (DFS): example implementation
    // --------------------------------------------------------------
    void dfs(int v) {
        std::cout << v << " "; // show node order
        nodes[v].visited = true;
        for (auto e : nodes[v].adj) {
            int w = e.dest;
            if (!nodes[w].visited)
                dfs(w);
        }
    }

    // --------------------------------------------------------------
    // Breadth-First Search (BFS): example implementation
    // --------------------------------------------------------------
    void bfs(int v) {
        for (int i = 1; i <= n; i++) nodes[i].visited = false;
        std::queue<int> q; // queue of unvisited nodes
        q.push(v);
        nodes[v].visited = true;
        while (!q.empty()) { // while there are still unvisited nodes
            int u = q.front(); q.pop();
            std::cout << u << " ";  // show node order
            for (auto e : nodes[u].adj) {
                int w = e.dest;
                if (!nodes[w].visited) {
                    q.push(w);
                    nodes[w].visited = true;
                }
            }
        }
    }


    // --------------------------------------------------------------

    // ---------------------------------------------------------
    // TODO: put the functions you need to implement below this
    // ---------------------------------------------------------

// * 58
    int distance(int a, int b) {
        // set up
        for (int i = 1; i <= n; i++) nodes[i].visited = false;
        std::queue<int> q;
        q.push(a);
        nodes[a].visited = true;
        nodes[a].dist = 0; // distance to self is 0;

        // solution 
        int res = 0;
        bool found = false;
        if (a == b) return 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            res++;
            for (Edge e : nodes[u].adj) {
                int w = e.dest;
                if (!nodes[w].visited) {
                    q.push(w);
                    nodes[w].visited = true;
                    nodes[w].dist = nodes[u].dist + 1; // node is 1 deeper than u
                }
                if (w == b) {  // if found node was equal to B, the first time it is should be the shortest path
                    found = true;
                    res = nodes[w].dist;
                    break;
                }
            }
        }
        return found ? nodes[b].dist : -1;
    }

    //* 59
    int diameter() {
        for (int i = 1; i <= n; i++) { nodes[i].visited = false; nodes[i].dist = 0; }
        int dia = 0;
        for (int i = 1; i <= n; i++) {
            dbfs(i);
            for (int i = 1; i <= n; i++) {
                if (!nodes[i].visited) return -1;
                dia = std::max(dia, nodes[i].dist);
                nodes[i].visited = false; nodes[i].dist = 0;
            }
        }
        return dia;
    }

    void dbfs(int i) {
        std::queue<int> q;
        q.push(i);
        nodes[i].visited = true;
        nodes[i].dist = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (Edge e : nodes[u].adj) {
                int w = e.dest;
                if (!nodes[w].visited) {
                    q.push(w);
                    nodes[w].visited = true;
                    nodes[w].dist = nodes[u].dist + 1; // node is 1 deeper than u
                }
            }
        }
    }

    //* 61
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
    //* 61
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

    //* 62
    std::list<int> shortestPath(int a, int b) {
        // setup
        for (int i = 1; i <= n; i++) { nodes[i].visited = false; nodes[i].dist = 0;nodes[i].order = 0; }
        std::list<int> res;
        std::queue<int> q;
        int c = -1;
        q.push(a);
        nodes[a].visited = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (Edge e : nodes[u].adj) {
                int w = e.dest;
                if (!nodes[w].visited) {
                    q.push(w);
                    nodes[w].visited = true;
                    nodes[w].dist = u;
                }
                if (w == b) {
                    c = b;
                    break;
                }
            }
        }
        if (c != b) return res;
        res.push_back(b);
        while (nodes[c].dist != a) {
            res.push_front(nodes[c].dist);
            c = nodes[c].dist;
        }
        res.push_front(a);
        return res;
    }


};

#endif