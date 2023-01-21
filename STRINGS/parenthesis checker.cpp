 bool ispar(string x)
    {
        // Your code here
        stack<char>s;
        
        for(int i=0 ; i<x.length() ; i++){
            char ch= x[i];
            
            // When opening brackets..
            if(ch=='(' || ch== '{' || ch=='['){
               s.push(ch);
               
            }
            else  // When closing brackets..
            {
                
                if(!s.empty()){
                    
                    char top= s.top();
                    
                    // For Matching..
                     if((ch==')' && top=='(') || (ch=='}' && top=='{')|| (ch==']' && top=='[')){
                         s.pop();
                         }
                     else
                      {
                         return false;  // Saying unbalanced..
                      }
                    
                }
                else{
                    return false;
                }
            }
        }
        // At last , checcking Stack..
        if(s.empty()){
            return true;
        }
        else{
            return false;
        }
        
    }