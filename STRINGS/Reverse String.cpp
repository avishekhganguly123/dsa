// method 1- T.C-O(n) S.C-O(n)

class Solution {
public:
    void reverseString(vector<char>& s) {
        //create a stack
        stack<char> st;
        //loop through the string, to add all the string elements in stack
        for(int i=0;i<s.size();i++){
            //create a variable to add the values
            char ch = s[i];
            st.push(ch);
        }
        //empty the original string
        s.clear();
        //add the stack elements to the string
        while(!st.empty()){
            char ch = st.top();
            //reversed
            s.push_back(ch);
            st.pop();
        }
    }
};

// method 2- 

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i++], s[j--]); 
        }
        
        return s;
    }
};

// method 3

class Solution {
public:
    void reverseString(vector<char>& s) {
       reverse(s.begin(),s.end());
        for (auto it:s){
            cout<<it<<",";
        }
    }
};

