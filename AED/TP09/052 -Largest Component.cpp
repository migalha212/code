//* for full implementation in practice of the code check graph.h

/*
	int largestComponent()
	{
		*setup
		int res = 0;
		for (int i = 1; i <= n; i++)
			nodes[i].visited = false;

		for (int i = 1; i <= n; i++){
			if(!nodes[i].visited){
				res = std::max(res,ldnf(i,1));
			}
		}
		return res;
	}
    
	int ldnf(int v, int count){
		nodes[v].visited = true;
		for(Edge edge : nodes[v].adj){
			int w = edge.dest;
			if(!nodes[w].visited){
				count += ldnf(w,1);
			}
		}
		return count;
	}
*/