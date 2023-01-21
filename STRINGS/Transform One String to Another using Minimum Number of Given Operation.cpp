int transform (string A, string B)
    {
        //code here.
        int ans=0;
        int i=B.size()-1;
        if(A.size()!=B.size()) return -1;
        for(int j=A.size()-1;j>=0;j--){
            if(A[j]!=B[i]) ans++;
        else{
            i--;
        }
        }
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        if(A!=B) return -1;
        return ans;
    }