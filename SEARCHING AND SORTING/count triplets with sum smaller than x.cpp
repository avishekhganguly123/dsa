long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	  sort (arr, arr+n);
	     
	      long long int cnt=0;
	      for (int i=0; i< n-2; i++){
	          
	          int j= i+1;
	          int k= n-1;
	          
	          while (j < k){
	              
long long int curr_sum= arr[i] + arr[j]+ arr[k];
	              
	               if (curr_sum < sum){
	                   cnt += k-j;
	                    j++;
	               }
	                  
	              else 
	               k--;
	           }
	        }
	         return cnt;
      	}