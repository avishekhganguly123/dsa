 int *findTwoElement(int *arr, int n) {
        
        // code here
         int *ans=new int[2];
         int cnt[n+1]={0};
        int a,b;
        for(int i=0;i<n;i++){
           cnt[arr[i]]++;
        }
        
        for(int i=0;i<n+1;i++){
            if(cnt[i]==0) ans[1]=i;
            if(cnt[i]>1) ans[0]=i;
        }
       
        return ans;
    }