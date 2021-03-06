// Segment tree supporting 1D queries and updates, if non-perfect binary tree, pad with zeroes to make perfect
void build(){
    for(int i = n - 1; i >= 0; i--){
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
}  

void modify(int p, int value){
    for(tree[p += n] = value; p > 1; p >>= 1)
        tree[p >> 1] = tree[p] + tree[p ^ 1];
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += tree[l++];
        if (r&1) res += tree[--r];
    }
    return res;
}
