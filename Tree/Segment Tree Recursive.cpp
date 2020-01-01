
int segTree[4 * 100001];

void construct(int node, int start, int end, int arr[]){
    // Leaf node
    if(start == end){
        segTree[node] = arr[start];
    }
    // Construct left and right child of tree
    else{
        int mid = (start + end) / 2;
        construct(2 * node, start, mid, arr);
        construct(2 * node + 1, mid + 1, end, arr);
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

int update(int node, int ll, int rl, int q, int val){
    // 
    if (rl < q || ll > q) return seg_tree[node];
    if (q == ll && q == rl) seg_tree[node] = val;
    else {
        int left = update(2*node+1, ll, (ll+rl)/2, q, val);
        int right = update(2*node+2, (ll+rl)/2 + 1, rl, q, val);
        st[node] = left + right;
    }
    return st[node];
}

int query(int index, int l_l, int l_r, int q_l, int q_r){
    // Total overlap, return node value
    if(q_l <= l_l && q_r >= l_r){
        return seg_tree[index];
    }
    // Out of range: return dummy value
    else if(q_l > l_r || q_r < l_l){
        return 0;
    }
    // Partial overlap, return combination of both children
    else{
        int left = query(2 * index + 1, l_l, (l_l + l_r) / 2, q_l, q_r);
        int right = query(2 * index + 2, (l_l + l_r) / 2 + 1, l_r, q_l, q_r);
        return left + right;
    }
}
