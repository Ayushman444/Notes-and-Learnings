int solve(int i, int j, const string &A, const string &B, vector<vector<int>> &dp) {
    if (i == 0 || j == 0)
        return (i == 0) ? j : i ;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (A[i-1] == B[j-1]) {
        return dp[i][j] = solve(i - 1, j - 1, A, B, dp);
    } else {
        return dp[i][j] = 1 + min(solve(i - 1, j, A, B, dp), min(solve(i, j - 1, A, B, dp),solve(i-1,j-1,A,B,dp)));
    }
}

int Solution::minDistance(string A, string B) {
    int n = A.size();
    int m = B.size();
    // if(n==1 and m==1 ) return 1;
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1]==B[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    
    // return solve(n , m , A, B, dp);
    return dp[n][m];
    
    
    
}
