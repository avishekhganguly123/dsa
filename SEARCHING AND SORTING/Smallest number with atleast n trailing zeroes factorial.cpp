        //method 1
        int findNum(int n)
        {
        //complete the function here
        if(n==1) return 5;
        int low =0;
        int high=n*5;

        
        while(low<=high){
            int mid=low+((high-low)/2);
            int cnt=0;
            int prod=5;
            while(prod<=mid){
                cnt+=mid/prod;
                prod*=5;
            }
            if(cnt>=n){

                high=mid-1;
            } 
            else low=mid+1;
        }
        return low;
        
        }

        //method 2

        int findNum(int n)
        {
            int low = 0;
            int high = n*5;
            int ans = high;
            while(low <= high){
                int mid = low + (high - low)/2;
                int count = 0;
                int num = 5;
                while(mid/num != 0){
                    count += mid/num;
                    num *= 5;
                }
                if(count < n){
                    low = mid + 1;
                }
                else{
                    ans = min(ans, mid);
                    high = mid - 1;
                }
            }
            return ans;
        }