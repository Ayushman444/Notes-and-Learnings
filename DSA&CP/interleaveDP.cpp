int solve(int i, int j, string &A, string &B, string &C, vector<vector<int>> &dp) {
    if (i == 0 && j == 0) {
        return 1; 
    }
    if (i == 0) {
        return (B.substr(0, j ) == C.substr(0, j));
    }
    if (j == 0) {
        return (A.substr(0, i) == C.substr(0, i));
    }
    
    if(dp[i][j]!=-1) return dp[i][j];

    int k = i + j;
    if (A[i-1] == C[k-1] && B[j-1] == C[k-1]) {
        return dp[i][j] = solve(i - 1, j, A, B, C, dp) || solve(i, j - 1, A, B, C, dp);
    } else if (A[i-1] == C[k-1]) {
        return dp[i][j] = solve(i - 1, j, A, B, C, dp);
    } else if (B[j-1] == C[k-1]) {
        return dp[i][j] = solve(i, j - 1, A, B, C, dp);
    } else {
        return dp[i][j] = 0;
    }
}

int Solution::isInterleave(string A, string B, string C) {
    int n = A.size();
    int m = B.size();
    int k = C.size();
    if (n + m != k) return 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return solve(n , m , A, B, C, dp);
}
