//! for full implementation of graph and function in practice check TP10/graph.h

/*
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

    void dbfs(int i){
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
*/