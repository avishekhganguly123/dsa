// method 1(this may give tle)
class Solution {
public:
bool ispali(string s){
    int i = 0;
    int j = s.size()-1;
    while(i<=j){
        if(s[i] != s[j]){
            return false;
        }
        i++;j--;
    }return true;
}
    int minChar(string str){
        //Write your code here
        int i = 0;
        int count = 0;
        while(i<str.size()){
            if(ispali(str.substr(0,i+1))){
                count = max(count,i+1);
            }
            i++;
        }
        return str.size()-count;
    }
}

//method 2(using lps)
    vector<int> computeLPSArray(string str){
    int M = str.length();
    vector<int> lps(M);
 
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (str[i] != str[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
 
    
    int minChar(string str){
        //Write your code here
        string revStr = str;
        reverse(revStr.begin(), revStr.end());
 
        // Get concatenation of string, special character
        // and reverse string
        string concat = str + "$" + revStr;
 
        //  Get LPS array of this concatenated string
        vector<int> lps = computeLPSArray(concat);
 
        // By subtracting last entry of lps vector from
        // string length, we will get our result
        return (str.length() - lps.back());
    }

