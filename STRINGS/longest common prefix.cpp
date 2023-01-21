string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s=strs[0];
        string e=strs[strs.size()-1];
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]==e[i]) ans+=s[i];
            else break;
        }
        return ans;
    }