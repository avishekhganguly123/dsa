public:
    int maxSubStr(string str){
        //Write your code here
        int cnt0=0,cnt1=0,res=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='0') cnt0++;
            else cnt1++;
            
            if(cnt1==cnt0) res++;
        }
        
        if(cnt1!=cnt0) return -1;
        
        return res;
    }