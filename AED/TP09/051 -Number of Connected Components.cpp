//* for full implementation in practice of the code check graph.h

/*
    ! 51
    int nrConnectedComponents(){
      int res = 0;
      for (int i=1; i<=n; i++) nodes[i].visited = false;
      for (int i = 1; i <= n; i++){
        if(!nodes[i].visited){
          res++;
          cdnf(i);
        }
        
      }
      return res;
    }
    void cdnf(int v){
      nodes[v].visited = true;
      for(Edge edge : nodes[v].adj){
        int w = edge.dest;
        if(!nodes[w].visited){
          cdnf(w);
        }
      }
    }
*/