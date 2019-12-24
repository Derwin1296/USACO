ll a[MX];
int seg_tree[4 * MX];

int construct(int index, int left_interval, int right_interval){
    if(left_interval == right_interval){
        seg_tree[index] = a[left_interval];
    }
    else{
        int left = construct(2 * index + 1, left_interval, (left_interval + right_interval) / 2);
        int right = construct(2 * index + 2, (left_interval + right_interval) / 2 + 1, right_interval);
        seg_tree[index] = left + right;
    }
    return seg_tree[index];
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

int main()
{
}
