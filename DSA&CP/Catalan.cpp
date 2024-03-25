const long long mod = 1000000007;
int Solution::chordCnt(int A) {
    vector<long long> dp(A+1,0);
    dp[0]=1;
    dp[1]=1;
    for(long long i=2;i<=A;i++){
        long long l = 0;
        long long r = i-1;
        while(l<=i-1){
            dp[i] += (dp[l]*dp[r]);
            dp[i] %= mod;
            l++;
            r--;
        }
    }
    return dp[A]%mod;
}
