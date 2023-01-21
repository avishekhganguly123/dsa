// using binary search T.C-0(n*log n)
bool findPair(int arr[], int size, int n){
    //code
    
    sort(arr, arr+size);
    
    for(int i=0; i<size; i++){
        int find = arr[i] + n;
    //for case 1,2,3,4,5 and n-0 tou we do find = n+1 = 1 and we got 1 in search 
    // buts thats not valid so i+1 used to skip search of that element 
        int start = i+1;  
        int end = size-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(arr[mid] == find) return true;
            else if(arr[mid] > find) end = mid-1;
            else if(arr[mid] < find) start = mid+1;
        }
    }
    return false;

// T.C-0(n*log n) using two pointer
bool findPair(int arr[], int size, int n){
    
    sort(arr,arr+size);
   int i=0,j=1;
   while(i<size && j<size){
       if(arr[j]-arr[i]==n && i<j) return true;
       // this way it can also be done.
      // if(i==j) j++;
     // else if(arr[j]-arr[i]>n) i++;
     // else j++;
       else if(arr[j]-arr[i]>n) i++;
       else j++;
   }
   return false;
    
}