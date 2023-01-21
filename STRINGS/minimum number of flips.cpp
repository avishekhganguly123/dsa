int minFlips (string S)
{
     int n = S.size();
   int cntS1 = 0; // there are 2 posibility 1010101 || 01010101 we
   int cntS2 = 0;
   for(int i=0;i<n;i++) {
       if(i%2==0 && S[i] == '1' || i%2!=0 && S[i] =='0') cntS1++;
       if(i%2==0 && S[i] == '0' || i%2!=0 && S[i] =='1') cntS2++;
   }
   
   return min(cntS1,cntS2);// your code here
}