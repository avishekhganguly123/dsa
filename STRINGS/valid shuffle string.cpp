// method 1
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        multimap<int,char>mp;
       // multimap<int, char>::iterator it;
        string ans;
        for(int i=0;i<s.size();i++){
            mp.insert({indices[i],s[i]});
        }
        for(auto it: mp){
            ans+=it.second;
        }
        return ans;
    }
};

//method 2

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
 
		string ans = s;
        for(int i =0; i < indices.size() ; i++) ans[indices[i]] = s[i];
        return ans;
    }
};