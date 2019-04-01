//Check whether it is possible to color a graph in two colors such that no two adjacent vertices share the same color

bool splitPartition(int c, int vertex){// odd = 1, even = 2
    if(color[vertex] != 0){
        return color[vertex] == c;
    }
    else{
        bool stillValid = true;
        // Color this vertex, visit neighbors
        color[vertex] = c;
        OE[c - 1] ++;
        vi n = adjList[vertex];
        for(auto v : n){
            stillValid = splitPartition(3 - c, v);
            if(!stillValid){
                return false;
            }
        }
        return true;
    }
}
