//method 1 without using divide operator
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here        
               long long int l=nums[0],r=nums[n-1];
        vector<long long int>v(n,1);
        for(int i=1;i<n;i++){
            v[i]*=l;
            l*=nums[i];
        }
        for(int i=n-2;i>=0;i--){
            v[i]*=r;
            r*=nums[i];
        }
        return v;

    }

    //method 2 using divide operator
        vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here        
       long long int p=1,cnt0=0;
        for(int i=0;i<n;i++) {
            if(nums[i]==0) cnt0++;
           else p=p*nums[i];
        }
        vector<long long int> res;
        for(int i=0;i<n;i++){
            if(nums[i]!=0 and cnt0==0){
                long long int temp=p;
               long long int v=p/nums[i];
                res.push_back(v);
                p=temp; 
            }
            else if(nums[i]==0 and cnt0==1) res.push_back(p);
            else res.push_back(0);
          
        }
        return res;
    }
