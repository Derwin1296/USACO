// Shortest Path with Heap
void dijkstra(int vertex){
    set<pair<ll, int>> toProcess;
    toProcess.insert({0, vertex});
    dist[0] = 0;
    while(!toProcess.empty()){
        pair<ll, int> p = *toProcess.begin();
        ll curDist = p.f;
        int curV = p.s;
        // Relax vertex, visit neighbors
        toProcess.erase(toProcess.begin());
        vis[curV] = true;
        vector<pair<ll, int>> n = adjList[curV];
        for(int i = 0; i < n.size(); i++){
            pair<ll, int> data = n[i];
            int adjV = data.s; ll d = adjMatrix[adjV][curV];
            if(!vis[adjV]){
                if(curDist + d < dist[adjV]){
                    dist[adjV] = curDist + d;
                    parent[adjV] = curV;
                    toProcess.insert({dist[adjV], adjV});
                }
            }
        }
    }
}
