int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_set<string>s;
        for(auto i:B) s.insert(i);
        
        int n=A.length();
        int dp[n+1]={0};
        dp[0]=1;
        
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                string cur=A.substr(j,i-j+1);
                if(dp[j] && s.find(cur)!=s.end()) {
                    dp[i+1]=1;
                    break;
                }
                else dp[i+1]=0;
            }
        }
        return dp[n];
    }