vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        unordered_map<string,vector<string>>mp;
        
        for(int i=0;i<string_list.size();i++){
            string cur=string_list[i];
            sort(cur.begin(),cur.end());
            mp[cur].push_back(string_list[i]);
        }
        
        for(auto i:mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }