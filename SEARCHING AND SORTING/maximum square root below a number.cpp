  int countSquares(int N) {
        // code here
        int cnt=0,i=1;
        while(i*i<N){
            cnt++;
            i++;
        }
        return cnt;
    }