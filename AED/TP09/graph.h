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
        int state = 0;
    };

    int n;                   // Graph size (vertices are numbered from 1 to n)
    bool hasDir;             // false: undirected; true: directed
    std::vector<Node> nodes; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int num, bool dir = false) : n(num), hasDir(dir), nodes(num + 1) {}

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1)
    {
        if (src < 1 || src > n || dest < 1 || dest > n)
            return;
        nodes[src].adj.push_back({dest, weight});
        if (!hasDir)
            nodes[dest].adj.push_back({src, weight});
    }

    // --------------------------------------------------------------

    // Read a graph in the format:
    // nr_nodes directed/undirected weighted/unweighted
    // nr_edges
    // src_1 dest_1 <weight_1>
    // src_2 dest_2 <weight_2>
    // ...
    // src_n dest_n <weight_n>
    static Graph *readGraph()
    {
        int n;
        std::string sdirection, sweight;
        std::cin >> n >> sdirection >> sweight;
        bool directed = (sdirection == "directed") ? true : false;
        bool weighted = (sweight == "weighted") ? true : false;

        Graph *g = new Graph(n, directed);
        int e;
        std::cin >> e;
        for (int i = 0; i < e; i++)
        {
            int u, v, w = 1;
            std::cin >> u >> v;
            if (weighted)
                std::cin >> w;
            g->addEdge(u, v, w);
        }
        return g;
    }

    // --------------------------------------------------------------
    // Depth-First Search (DFS): example implementation
    // --------------------------------------------------------------
    void dfs(int v)
    {
        // std::cout << v << " "; // show node order
        nodes[v].visited = true;
        for (auto e : nodes[v].adj)
        {
            int w = e.dest;
            if (!nodes[w].visited)
                dfs(w);
        }
    }

    // --------------------------------------------------------------
    // Breadth-First Search (BFS): example implementation
    // --------------------------------------------------------------
    void bfs(int v)
    {
        for (int i = 1; i <= n; i++)
            nodes[i].visited = false;
        std::queue<int> q; // queue of unvisited nodes
        q.push(v);
        nodes[v].visited = true;
        while (!q.empty())
        { // while there are still unvisited nodes
            int u = q.front();
            q.pop();
            std::cout << u << " "; // show node order
            for (auto e : nodes[u].adj)
            {
                int w = e.dest;
                if (!nodes[w].visited)
                {
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

    //! 49
    int outDegree(int v)
    {
        return nodes[v].adj.size();
    }

    //! 50
    int weightedOutDegree(int v)
    {
        int res = 0;
        for (Edge edge : nodes[v].adj)
        {
            res += edge.weight;
        }
        return res;
    }

    //! 51
    int nrConnectedComponents()
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
            nodes[i].visited = false;
        for (int i = 1; i <= n; i++)
        {
            if (!nodes[i].visited)
            {
                res++;
                dfs(i);
            }
        }
        return res;
    }

    //! 52
    int largestComponent()
    {
        // setup
        int res = 0;
        for (int i = 1; i <= n; i++)
            nodes[i].visited = false;

        for (int i = 1; i <= n; i++)
        {
            if (!nodes[i].visited)
            {
                res = std::max(res, ldnf(i, 1));
            }
        }
        return res;
    }

    int ldnf(int v, int count)
    {
        nodes[v].visited = true;
        for (Edge edge : nodes[v].adj)
        {
            int w = edge.dest;
            if (!nodes[w].visited)
            {
                count += ldnf(w, 1);
            }
        }
        return count;
    }

    //! 53
    std::list<int> topologicalSorting()
    {
        // setup
        std::list<int> res = {};
        for (int i = 1; i <= n; i++)
            nodes[i].visited = false;
        // resolution
        for (int i = 1; i <= n; i++)
        {
            if (!nodes[i].visited)
            {
                tdfs(i, res);
            }
        }
        return res;
    }

    void tdfs(int v, std::list<int> &res)
    {
        nodes[v].visited = true;

        for (Edge edge : nodes[v].adj)
        {
            int w = edge.dest;
            if (!nodes[w].visited)
            {
                tdfs(w, res);
            }
        }

        res.push_front(v);
    }

    //! 54
    bool hasCycle(){
        //setup
        bool res = false;
        for (int i = 1; i <= n; i++)
            nodes[i].visited = false;
        //resolution
        for(int i = 1; i <= n; i++){
            if(!nodes[i].visited){
                res = hdfs(i);
            }
            if(res) return res;
        }
        return res;
    }
    bool hdfs(int v){
        bool flag = false;
        nodes[v].visited = true;
        nodes[v].state = 1; //looking into children
        for(Edge edge : nodes[v].adj){
            int w = edge.dest;
            if(nodes[w].state == 1) flag = true;
            else if (nodes[w].state == 0) 
                flag = hdfs(w);
            if(flag) return flag;
        }
        nodes[v].state = 2;
        nodes[v].visited = true;
        return flag;
    }

    //! 55
    bool isBipartite(){

    }
};

#endif