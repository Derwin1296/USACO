class subset{
    public:
        int parent;
        int rank;
    subset(){}
};
int find(subset subsets[], int i){
    if(subsets[i].parent != i){
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
void Union(subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if(subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }
    else if(subsets[yroot].rank < subsets[xroot].rank){
        subsets[yroot].parent = xroot;
    }
    else{
        subsets[xroot].parent = yroot;
        subsets[yroot].rank += 1;
    }
}
int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    // List of parent vertices
    subset subsets[g_nodes];
    for(int v = 0; v < g_nodes; v++){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }  
    // Create vector of edges in ascending order <w, <w + u + v, <u, v>>
    vector<pair<int, pair<int, pair<int, int>>>> edge_list;
    for(int i = 0; i < g_from.size(); i++){
        int w = g_weight[i]; int u = g_from[i]; int v = g_to[i];
        edge_list.push_back(mp(w, mp(w + u + v, mp(u, v))));
    }
    sort(edge_list.begin(), edge_list.end());
    // Go through edge list, add vertices which aren't in the set to set
    set<int> vertices;
    int t_wt = 0;
    for(int i = 0; i < g_from.size(); i++){
        pair<int, pair<int, pair<int, int>>> data = edge_list[i];
        // If both vertices in set, continue
        cout << data.f << ", " << data.s.s.f << ", " << data.s.s.s << "\n";
        int x = find(subsets, data.s.s.f - 1);  
        int y = find(subsets, data.s.s.s - 1);
        if(x != y){
            t_wt += data.f;
            Union(subsets, x, y);
        }
    }
    return t_wt;
}
