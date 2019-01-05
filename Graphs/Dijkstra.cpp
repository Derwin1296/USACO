for(int i = 1; i <= n; i++) d[i] = INF;
d[root] = 0;

void dijkstra(int root){
  std :: priority_queue<pi> q;
  q.push({root, 0});
  
  while(!q.empty()){
    pi cPair = q.front();
    q.pop();
    
    int v = cPair.f; int dist = cPair.s;
    if(vis[v]) continue;
    vis[v] = true;
    
    vector<pi> n = adjList[v];
    for(auto p : n){
        int vertex = p.f; int weight = p.s;
        if(d[v] + weight < d[vertex]){
            d[vertex] = d[v] + weight;
            q.push({-d[vertex], vertex);
        }
    }
  }
}
