class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int n=s1.size();
        int m =s2.size();
        if(n!=m) return false;
        else{
          s1=s1+s1;
          if(s1.find(s2)!=-1) return true;
          else return false;
        }
     return 0;   
    }
    
};