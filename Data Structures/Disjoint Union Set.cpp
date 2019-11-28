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
