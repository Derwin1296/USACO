// Generate all possible subsets of a set of n integers
vector<vector<int>> genSub(vector<int> list){
    vector<vector<int>> fSet;
    // All #s up to 2^(# elements in the set)
    for(int i = 0; i < pow(2, list.size()); i++){
        vector<int> subset;
        for(int j = 0; (1 << j) <= i; j++){
            if(i & (1 << j)){
                subset.pb(list[j]);
            }
        }
        fSet.pb(subset);
    }
    return fSet;
}
