int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n==1) return arr[0];
        int a=arr[0];
        int b=max(a,arr[1]);
        
        for(int i=2;i<n;i++){
            int sum=max(b,a+arr[i]);
            a=b;
            b=sum;
        }
        return b;
    }