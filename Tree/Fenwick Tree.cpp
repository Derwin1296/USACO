struct BIT{
   int tree[1000] = {0};
   int size;
   BIT(int arr[], int n){
        size = n + 1;
        for(int i = 0; i < n; i++){
            update(arr[i], i);
            // cout << "Done updating! \n";
        }
   }
   void update(int val, int ind){
       ind = ind + 1;
       while(ind <= size){
           tree[ind] += val;
           ind += ind & (-ind);
        //   cout << "Current index: " << ind << "\n";
       }
   }
   int sum(int ind){
       int total = 0;
       ind = ind + 1;
       while(ind > 0){
           total += tree[ind];
           ind -= ind & (-ind);
       }
       return total;
   }
};
