//method 1
 void lps(string pat, vector<int> &ls){
        int len =0, i=1;
        ls[0]=0;
        while(i<pat.length()){
            if(pat[i] == pat[len]){
                len++;
                ls[i] = len;
                i++;
            }else{
                if(len ==0){
                    ls[i] = 0;
                    i++;
                }else{
                    len  = ls[len-1];
                }
            }
        }
    }
    
        vector <int> search(string pat, string txt)
        {
            //code hee.
            int n = pat.length();
            int m = txt.length();
            vector<int> ls(n);
            lps(pat, ls);
            int j=0,i=0;
            vector<int> ans;
           while(i<m){
                if(txt[i]==pat[j]){
                    i++;
                    j++;
                }
                if(j==n){
                    ans.push_back(i-j+1);
                    j = ls[j-1];
                  
                }else if(i<m && txt[i] != pat[j]){
                    if(j==0){
                        i++;
                    }else{
                        j = ls[j-1];
                    }
                }
                
            }
            return ans;
            
        }

		
// method 2
int lps(string s) {
	    // Your code goes here
	    int ls[s.length()]={0};
	    ls[0]=0;
	    int i=1,len=0;
	    while(i<s.length()){
	        if(s[len] == s[i]){
	            len++;
	            ls[i] = len;
	            i++;
	        }else{
	            if(len ==0){
	                ls[i]=0;
	                i++;
	            }else{
	                len = ls[len-1];
	            }
	        }
	    }
	    
	    
	    return ls[s.length()-1];
	}
