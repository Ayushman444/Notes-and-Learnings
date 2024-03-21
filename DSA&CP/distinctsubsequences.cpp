int solve(int i, int j , string &A, string &B, vector<vector<int>> &dp){
    if(j==0) return 1;
    if(i==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = 0;
    if(A[i-1]==B[j-1]) ans = solve(i-1,j-1,A,B,dp);
    ans += solve(i-1,j,A,B,dp);
    
    return dp[i][j] = ans;
}
int Solution::numDistinct(string A, string B) {
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int j=0;j<=m;j++){
        dp[0][j] = 0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int ans = 0;
            if(A[i-1]==B[j-1]) ans = dp[i-1][j-1];
            ans += dp[i-1][j];
            dp[i][j]=ans;
        }
    }
    return dp[n][m];
    // return solve(n,m,A,B,dp);
}
