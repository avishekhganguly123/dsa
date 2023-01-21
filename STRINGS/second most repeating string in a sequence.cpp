//method 1
 string secFrequent (string arr[], int n)
    {
        //code here.
        int mx=0;
        string s="";
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            if(m[arr[i]]>mx){
                mx=m[arr[i]];
                s=arr[i];
            }
        }
        
        m.erase(s);
        string ans="";
        mx=0;
        
        for(auto i:m){
            if(i.second>mx){
                mx=i.second;
                ans=i.first;
            }
        }
        
        return ans;
        
    }

//method 2(using sort)
unordered_map<string, int> um;
        string ans;
        for(int i=0; i<n; i++){
            um[arr[i]]++;
        }
        //to find second largest 
        vector<int> v;
        for(auto it: um){
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        int sec_repeating = v[v.size()-2];
        
        //returning its key
        for(auto it :um){
            if(it.second == sec_repeating) ans = it.first;
        }
        
        return ans;