 long long int dp[1001][1001];
    long long int l=1e9 +7;
    
    int solve(int i, int j, string &str){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(str[i]==str[j]) return dp[i][j]=(solve(i+1,j,str)+solve(i,j-1,str) + 1)%l;
        else return dp[i][j]=(l+solve(i+1,j,str)+solve(i,j-1,str)-solve(i+1,j-1,str))%l;
        
    }
    long long int  countPS(string str)
    {
       //Your code here
       memset(dp,-1,sizeof(dp));
       int n=str.length();
       return solve(0,n-1,str);
       
       
    }