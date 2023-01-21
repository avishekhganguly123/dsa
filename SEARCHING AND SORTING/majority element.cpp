// using moore voting algo and space complexity 0(1)
int majorityElement(int a[], int size)
{
        
    int Maj=-1,vote=0;
        
    for(int i=0;i<size;i++){
        
        if(vote == 0){
            Maj = a[i];
            vote=1;
        }
        
        else if(a[i] != Maj)
            vote--;
        else
            vote++;
            
       
    }
    
    int cnt=0;
    for(int i=0;i<size;i++)
        if(a[i] == Maj)
            cnt++;
            
    return cnt>(size/2)?Maj:-1;
    
}



// method 2 space complexity is O(n)
 int majorityElement(int a[], int size)
    {
        
        int rcnt=-1;
        int res=a[0];
        unordered_map<int,int>m;
        for(int i=0;i<size;i++){
            m[a[i]]++;
        }
        
        for(auto &i:m){
            if(i.second>m[res]) res=i.first;
        }
        
        if(m[res]>size/2) return res;
        else res=-1;
        
        return res;
        
    }