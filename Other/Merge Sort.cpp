void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1]; int R[n2];
    // Load into copies of left and right array
    for(int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
    // Sort the two arrays by pointers
    int l_pointer = 0;
    int r_pointer = 0;
    int cur_merged_index = l;
    while(l_pointer < n1 and r_pointer < n2){
        int left_ele = L[l_pointer];
        int right_ele = R[r_pointer];
        // cout << left_ele << ", " << right_ele << "\n";
        if(left_ele < right_ele){
            arr[cur_merged_index] = left_ele;
            l_pointer ++;
        }
        else{
            arr[cur_merged_index] = right_ele;
            r_pointer ++;
        }
        // cout << "Current element added: " << arr[cur_merged_index] << "\n";
        cur_merged_index++;
    }
    // Remaining left and right elements
    while(l_pointer < n1){
        arr[cur_merged_index] = L[l_pointer];
        l_pointer ++;
        cur_merged_index++;
    }
    while(r_pointer < n2){
        arr[cur_merged_index] = R[r_pointer];
        r_pointer ++;
        cur_merged_index++;
    }
}
void merge_sort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        // cout << "Trying to merge_sort: " << l << ", " << m << "\n";
        merge_sort(arr, l, m);
        // cout << "Trying to merge_sort: " << (m + 1) << ", " << r << "\n"; 
        merge_sort(arr, m + 1, r);
        // cout << "Merging: " << l << ", " << m << ", " << r << "\n";
        merge(arr, l, m, r);
    }
}
