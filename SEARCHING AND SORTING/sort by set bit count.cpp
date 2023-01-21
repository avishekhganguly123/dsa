//method 1

    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        multimap<int,int,greater<int>>m;
        for(int i=0;i<n;i++){
           int c= __builtin_popcount(arr[i]);
           m.insert({c,arr[i]});
        }
        
        int i=0;
        for(auto it:m){
            arr[i]=it.second;
            i++;
        }
    }

//method 2

static bool comp(int a,int b){
       return __builtin_popcount(a)>__builtin_popcount(b);
   }
   void sortBySetBitCount(int arr[], int n)
   {
       // Your code goes here
       stable_sort(arr,arr+n,comp);
   }