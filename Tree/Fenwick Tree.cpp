struct BIT{
    int tree[MX + 10];
    int size;
    // Creates tree with given size
    BIT(int n){
        size = n + 1;
    }
    // Updates tree
    void update(int k, int x){// k = index, x = value
        while(k <= size){
            tree[k] += x;
            k += (k & -k);
        }
    }
    // Find sum 1 to k
    int sum(int k){
        int s = 0;
        while(k >= 1){
            s += tree[k];
            k -= (k & -k);
        }
        return s;
    }
};
