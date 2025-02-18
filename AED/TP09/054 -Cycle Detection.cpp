//* for full implementation in practice of the code check graph.h

/*
    bool hasCycle(){
        //*setup
        bool res = false;
        for (int i = 1; i <= n; i++)
            nodes[i].visited = false;
        //*resolution
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
        nodes[v].state = 1; //*looking into children
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
*/