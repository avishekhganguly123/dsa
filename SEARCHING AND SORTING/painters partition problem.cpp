// it is exactly same as book allocation problem infcat code is also same
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long int low= *max_element (arr, arr+n);
        long long int high= 0;
        
         for (int i=0; i< n; i++)
                 high+= arr[i];
          
           while (low <= high){
               
       long long  int mid= low+ (high-low)/2;
       long long  int paintercount=0;
       long long int paintersum=0;
               
             for (int i=0; i<n; i++){
   // Note no curley bracakets use in loop           
              
              if(paintersum+arr[i] <= mid)
                  paintersum+= arr[i];
                 
                else{
                    paintercount++;
                    paintersum= arr[i];
                  }
             }
             if (paintersum > 0)
                  paintercount++;
          
          if (paintercount >  k)
                   low= mid+1;
                  
                 else
                  high= mid-1;
             
           }
           
           return low;
    }