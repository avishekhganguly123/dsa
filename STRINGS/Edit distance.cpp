int dp[105][105];
  int solve(string s,string t,int n,int m){
      if(m==-1) return n+1;
      if(n==-1) return m+1;
      
      if(dp[n][m]!=-1) return dp[n][m];
      
      if(s[n]==t[m]) return dp[n][m]=solve(s,t,n-1,m-1);
      
      int a=solve(s,t,n-1,m-1);
      int b=solve(s,t,n-1,m);
      int c=solve(s,t,n,m-1);
      
      return dp[n][m]=1+min({a,b,c});
  }
    int editDistance(string s, string t) {
        // Code here
        memset(dp,-1,sizeof(dp));
        int n=s.length();
        int m=t.length();
        return solve(s,t,n-1,m-1);
        
    }