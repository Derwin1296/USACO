int segTree[4 * MX];
int lazy[4 * MX];

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

void update(int node, int start, int end, int index, int val, int arr[]){
    // If leaf node, update value
    if(start == end){
        // cout << "Current index updating";
        arr[index] += val;
        segTree[node] += val;
    }
    // Otherwise, determine if index lies in left or right child
    else{
        int mid = (start + end) / 2;
        // If on left child, update left
        if(start <= index && index <= mid){
            cout << "Updating left! \n";
            update(2 * node, start, mid, index, val, arr);
        }
        // Otherwise, update right
        else{
            cout << "Updating right! \n";
            update(2 * node + 1, mid + 1, end, index, val, arr);
        }
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

int query(int node, int start, int end, int l, int r){
    // Node range completely within query range
    if(l <= start && end <= r){
        return segTree[node];
    }
    // Query range completely outside node range
    else if(l > end || r < start){
        return 0;
    }
    else{
        int mid = (start + end) / 2;
        // Query on left and right child
        int l_q = query(2 * node, start, mid, l, r);
        int r_q = query(2 * node + 1, mid + 1, end, l, r);
        return l_q + r_q;
    }
}

void updateRange(int node, int start, int end, int l, int r, int val){
    // Out of range:
    if(l > end || r < start || end < start){
        return;
    }
    // Current node is leaf node
    else if(start == end){
        segTree[node] += val;
        return;
    }
    // Recursion on children, update tree[node]
    else{
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

void updateRangeLazy(int node, int start, int end, int l, int r, int val){
    if(lazy[node] != 0){
        // Update this node
        segTree[node] += (end - start + 1) * val;
        // Queue children nodes to be updated
        if(start != end){
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        // Reset to zero
        lazy[node] = 0;
    }
    // Out of range:
    if(start > end || l > end || r < start){
        return;
    }
    // Fully within range:
    if(l <= start && r <= end){
        segTree[node] += (end - start + 1) * val;
        // Not a tree node
        if(start != end){
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRangeLazy(2 * node, start, mid, l, r, val);
    updateRangeLazy(2 * node + 1, mid + 1, end, l, r, val);
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}
