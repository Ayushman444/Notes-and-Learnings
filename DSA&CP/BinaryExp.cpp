int func(int a, int b){
    int ans = 1;
    while(b>0){
        if(b&1){
            ans=ans*a;
            b-=1;
        }else{
            a = a*a;
            b/=2;
        }
    }
    return ans;

}