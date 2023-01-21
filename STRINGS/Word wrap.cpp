 int solveWordWrap(vector<int>nums, int k) 
    { 
        int n=nums.size();
        int i,j,cost,curlen;
        int dp[n],ans[n];
        dp[n-1]=0;
        ans[n-1]=n-1;
        
        for(i=n-2;i>=0;i--){
            curlen=-1;
            dp[i]=INT_MAX;
            
            for(j=i;j<n;j++){
                curlen+= (nums[j]+1);
                
                if(curlen>k) break;
                
                if(j == n-1) cost=0;
                
                else cost =(k-curlen)*(k-curlen) + dp[j+1];
                
                if(cost<dp[i]){
                    dp[i]=cost;
                    ans[i]=j;
                }
            }
            
        }
        
      return dp[0];
    } 