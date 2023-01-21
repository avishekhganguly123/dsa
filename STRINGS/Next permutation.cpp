public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int i1,i2;
        if(N==1) return arr;
        for(i1=N-2;i1>=0;i1--){
            if(arr[i1]<arr[i1+1]) break;
            
        }
        
        if(i1<0){
            reverse(arr.begin(),arr.end());
            return arr;
        } 
        
          for(i2=N-1;i2>=0;i2--){
            if(arr[i2]>arr[i1]) {
                swap (arr[i2],arr[i1]);
                break;
            }
        }  
        
        
        
        reverse(arr.begin()+i1+1,arr.end());
        return arr;
    }