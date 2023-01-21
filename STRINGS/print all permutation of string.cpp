	public:
	
	    void solve(int index,vector<string>&res,string s){
	        if(index==s.size()){
	            res.push_back(s);
	            return;
	        }
	        
	        for(int i=index;i<s.size();i++){
	            if(i>index && s[i]==s[i-1]) continue;
	            swap(s[index],s[i]);
	            solve(index+1,res,s);
	            swap(s[index],s[i]);
	        }
	        
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>res;
		    solve(0,res,S);
		    sort(res.begin(),res.end());
		    return res;
		    
		    
		}