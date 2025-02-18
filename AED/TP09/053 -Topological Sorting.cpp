//* for full implementation in practice of the code check graph.h

/*
    std::list<int> topologicalSorting()
    {
        * setup
        std::list<int> res = {};
        for (int i = 1; i <= n; i++)
            nodes[i].visited = false;
        * resolution
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
*/