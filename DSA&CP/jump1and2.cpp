int Solution::canJump(vector<int> &A) {
    int n = A.size();
    int goal = n-1;
    for(int i = n-1;i>=0;i--){
        if(i+A[i]>=goal) goal = i;
    }
    return !(goal>0);
}


int Solution::jump(vector<int> &A) {
    int n = A.size();
    int res  = 0;
    int l = 0, r = 0;
    while(r<n-1){
        int farthest = 0;
        for(int i = l;i<=r;i++){
            farthest = max(farthest,i+A[i]);
        }
        l = r+1;
        r = farthest;
        if(l>r) return -1;
        res+=1;
    }
    return res;
}
