int inSequence(int A, int B, int C){
        // code here
        if(C==0){
            if(A==B) return 1;
            else return 0;
        }
        int d=(B-A)/C;
        int e=(B-A)%C;
        return d>=0 && e==0;
    }