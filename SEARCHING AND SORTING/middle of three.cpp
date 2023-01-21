int middle(int a, int b, int c){
        //code here//Position this line where user code will be pasted.
        if(a<b && b<c || a>b && b>c){
           return b;
       }
       if(a<c && c<b || a>c && c>b){
           return c;
       }
       return a;
    }