//* for full implementation in practice of the code check graph.h

/*
bool isBipartite() {
        for (int i = 1; i <= n; i++){
            nodes[i].visited = false;
            nodes[i].state = -1;
        }
        for(int i = 1; i <= n; i++){
            // if a node hasnt been collored yet
            if(nodes[i].state == -1){
                // if the dfs fails return false
                if(!dfs55(i,0)){
                    return false;
                }
            }
        }
        // if all vertex are collored correctly
        return true;
    }
    
    bool dfs55(int v,int colour){
        //* set the new node to the designated colour, either 1 or 0
        //* note that a node will only get here if it doesnt yet have a colour
        nodes[v].visited = true;
        nodes[v].state = colour;
        //* start looking into adjacent nodes
        for(Edge e : nodes[v].adj){
            int w = e.dest;

            //* if node hasnt been coloured check the underlying dfs
            if(nodes[w].state == -1){
                if(!dfs55(w,1 - colour)){
                    return false;
                }
            }
            //* if the same colour was found, its not bipartite
            else if(nodes[w].state == colour){
                return false;
            }
        }
        return true;
    }
*/