// see minimum swaps for bracket balancing(gfg) there is difference between them
int countRev (string s)
{
    if(s.length()%2==1) return -1;
    
    int open=0,ans=0;
    
    for(auto i:s){
        if(open==0 && i=='}'){
            open++;
            ans++;
        }
        else if(i=='}') open--;
        else if(i=='{'){
            open++;
        }
    }
    
    return ans + open/2;
}