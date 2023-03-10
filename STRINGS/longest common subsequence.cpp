class Solution {
public:
    int dp[1001][1001];
    
    int lcs(string &text1,string &text2,int n,int m){
        if(n==0 || m==0) return 0;
        
        if (dp[n][m]!=-1) return dp[n][m];
        
        if(text1[n-1]==text2[m-1]) return dp[n][m]= 1+lcs(text1,text2,n-1,m-1);
        else{
            return dp[n][m]= max(lcs(text1,text2,n,m-1),lcs(text1,text2,n-1,m));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
       return lcs(text1,text2,text1.length(),text2.length());
    }
};
