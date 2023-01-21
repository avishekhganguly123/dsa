// method 1
// when frequency of sum gets repeated it means in between 0 is crossed then only that number can gets repeated
// and initially freq[0]++ to manage a number equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        long long res=0;
        map<long long,int>freq;
        long long sum=0;
        freq[0]++;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            freq[sum]++;
            res+=freq[sum]-1;
        }
        return res;
    }

/* method 2
Now for a prefix sum [ prefix_sum[i] ],
if the count is 2 then there is 1 zero-sum subarray
if the count is 3 then there is 3 zero-sum subarray
if the count is 4 then there is 6 zero-sum subarray
if the count is n then there is nC2 = (n*(n-1))/2 zero-sum subarray
 
for the given array
count of presum value 5 is 3, so the ans is (3*2)/2=3,
count of presum value 8 is 2, so the ans is 3+(2*1)/2 = 3+1 = 4
count of presum value 6 is 2, so the ans is 4+(2*1)/2 = 4+1 = 5
 
Now if the array is                      { 0  0  1}
so the prefix sum array will be { 0  0  1}
count of 0 is 2, so the ans is (2*1)/2 = 1
This is wrong, we are considering the subarray {0, 0} only.
We have to consider {0}, {0} subarrays also.
To handle this case, if the value of presum is 0, we have to increase the answer.
*/

long long findSubarray(vector<long long> arr, int n ) {

        long long ans=0, zero=0, presum=0;

        unordered_map<long long, long long>mpp;

        for(int i=0;i<n;i++){

            presum+=arr[i];
            if(presum==0) ans++;
            mpp[presum]++;

        }

        for(auto it:mpp) {

            long long x=it.second;
            ans+= (x*(x-1))/2;

        }
        return ans;
    }