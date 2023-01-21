// method 1(striver)
int isvalid(int A[],int N,int M,int mid)
   {
       int sum=0;
       int count=0;
       for(int i=0;i<N;i++)
       {
           if(A[i]>mid)
           return 0;
           else
           {
               sum+=A[i];
               if(sum>mid)
               {sum=0;
               sum=A[i];
               count++;
               }
         }
           }
       if(sum<=mid)
       count++;
       
       if(count<=M)
       return 1;
       return 0;
       
       
   }
   int findPages(int A[], int N, int M) 
   {
       //code here
       if(M>N) return -1;
       long long ans=INT_MAX;
       long long int l=0,h=0;
       for(int i=0;i<N;i++)
       h+=A[i];
       while(l<=h)
       {
           long long mid=h-((h-l)/2);
           if(isvalid(A,N,M,mid))
           {
               if(mid<ans)
               ans=mid;
               h=mid-1;
               
           }
           else
           l=mid+1;
           
       }
       return ans;
   }

   //method 2

   int findPages(int A[], int N, int M) 
    {
        //code here(code is getting run nut minute details are not mentioned here)
        if(M > N)
        return -1;
        int s=*max_element(A,A+N);
        int e=accumulate(A,A+N,0);
        while(s<=e){
            int m=s+((e-s)/2);
            int sum=0;
            int count=1;
            int i=0;
            while(i<N){
                sum+=A[i];
                if(sum>m) count++,sum=A[i];
                i++;
            }
            if(count>M) s=m+1;
            else e=m-1;
        }
        return s;
    }
