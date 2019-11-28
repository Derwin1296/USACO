vector<vector<int>> fin_lst;
// Generates all subsets of elements in a vector
void subsets(vector<int> cur_subset, vector<int> lst, int index){
    if(index == lst.size()){
        fin_lst.push_back(cur_subset);
    }
    else{
        subsets(cur_subset, lst, index + 1);
        cur_subset.push_back(lst[index]);
        subsets(cur_subset, lst, index + 1);
        cur_subset.pop_back();
    }
}
