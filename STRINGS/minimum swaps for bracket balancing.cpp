    // see count the reversal(gfg) there is difference between them.
    int minimumNumberOfSwaps(string S){
                int openBrackets = 0;
        int closeBrackets = 0;
        int ans = 0;
        for(auto &e : S){
            if(e == ']'){
                closeBrackets++;
            }
            else{
                if(closeBrackets > openBrackets){
                    ans += closeBrackets - openBrackets;
                }
                openBrackets++;
            }
        }
        return ans;
 
    }