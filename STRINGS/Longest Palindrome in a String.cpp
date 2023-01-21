class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int n=S.length();
        int start=0,len=1;
        
        for(int i=1;i<n;i++){
            //even
            int l=i-1;
            int r=i;
            while(l>=0 && r<=n-1 && S[l]==S[r]){
                
                    if(len<r-l+1){
                        len=r-l+1;
                        start=l;
                    }
                    l--;
                    r++;
                
                
            }
            //odd
            l=i-1;
            r=i+1;
             while(l>=0 && r<=n-1 && S[l]==S[r]){
                
                    if(len<r-l+1){
                        len=r-l+1;
                        start=l;
                    }
                    l--;
                    r++;

            }
        }
        return S.substr(start,len);
    }
};