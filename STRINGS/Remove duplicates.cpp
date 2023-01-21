class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        stack<char>st;
        vector<int>index(26,0);
        vector<bool>seen(26,false);
        for(int i=0;i<s.size();i++){
            index[s[i]-'a']=i;
        }
        
        for(int i=0;i<s.size();i++){
            int cur=s[i]-'a';
            if(seen[cur]) continue;

            while(st.size()>0 && i<index[st.top()-'a'] && st.top()>s[i]){
                seen[st.top()-'a']=false;
                st.pop();    
        }
            st.push(s[i]);
            seen[cur]=true;
        }
        
        while(st.size()>0){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};