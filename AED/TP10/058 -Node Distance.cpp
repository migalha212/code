//! for full implementation of graph and function in practice check TP10/graph.h

/*
    int distance(int a, int b) {
        *set up
        for (int i = 1; i <= n; i++) nodes[i].visited = false;
        std::queue<int> q;
        q.push(a);
        nodes[a].visited = true;
        nodes[a].dist = 0; // distance to self is 0;

        *solution
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
*/