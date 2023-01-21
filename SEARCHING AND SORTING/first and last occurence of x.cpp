vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int>res;
    int a=-1,b=-1;
   for(int i=0;i<n;i++){
       if(arr[i]==x){
           a=i;
           break;
       }
   }
   
   for(int i=n-1;i>=0;i--){
       if(arr[i]==x){
            b=i;
           break;
       }
   }
   
   res.push_back(a);
   res.push_back(b);
   
    return res;
}