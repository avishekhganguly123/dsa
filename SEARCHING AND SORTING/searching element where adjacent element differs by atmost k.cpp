int search(int arr[], int n, int x, int k)
{
    // Complete the function	
    int i=0;
    while(i<n){
        if(arr[i]==x) return i;
        else{
            int dif=abs(arr[i]-x)/k;
            i+=max(dif,1);
        }
    }
    return -1;
} 