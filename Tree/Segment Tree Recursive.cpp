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
