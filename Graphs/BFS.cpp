// Find shortest distance from each node to root with unweighted edges
void BFS(int vertex){
    std :: queue<pi> toProcess;
    toProcess.push({vertex, 0});
    while(!toProcess.empty()){
        pi cPair = toProcess.front();
        toProcess.pop();
        int v = cPair.f;
        int dist = cPair.s;
        // Visit
        visited[v] = true;
        distRoot[vertex] = dist;
        // Check neighbors, add to queue
        vector<int> n = adjList[v];
        for(auto i : n){
            if(!visited[i]){
                visited[i] = true;
                toProcess.push({i, dist + 1});
            }
        }
    }
}
