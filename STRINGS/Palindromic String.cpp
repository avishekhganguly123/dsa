class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int n=S.size();
	    int i=0,j=n-1;
	    while(j>i){
	        if(S[j]==S[i]) {
	            i++;
	            j--; 
	        }
	        else return 0;
	       
	    }
	    return 1;
	}

};