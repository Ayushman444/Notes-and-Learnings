bool solve(int i, int j, string &a,string &b,vector<vector<int>> &dp){
    //base case
    if(j==0 && i==0) return true;
    if(j==0 && i>=1) return false;
    if(i==0 && j>=1){
        for(int ii = 1;ii<=j;ii++){
            if(b[ii-1]!='*') return false;
        }
        return true;
    }
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    
    //same 
    if(a[i-1]==b[j-1] || b[j-1]=='?') return dp[i][j] = solve(i-1,j-1,a,b,dp);
    //not same
    
    if(b[j-1] =='*'){
        // bool ans = false;
        return dp[i][j] = (solve(i-1,j,a,b,dp) | solve(i,j-1,a,b,dp));
    }
    return dp[i][j] = false;
}


int Solution::isMatch(const string A, const string B) {
    
    string a = A;
    string b = B;
    int n = a.size();
    int m = b.size();
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    vector<int> prev(m+1);
    vector<int> curr(m+1);
    prev[0] = 1;
    // for(int i=1;i<=n;i++){
    //     dp[i][0] = 0;
    // }
    for(int j = 1;j<=m;j++){
        int ans = 1;
        for(int ii = 1;ii<=j;ii++){
            if(b[ii-1]!='*'){
                ans = 0;
                break;
            } 
        }
        prev[j] = ans;
    }
    
    for(int i=1;i<=n;i++){
        for(int j =0;j<=m;j++){
            if(j==0) curr[0] = 0;
            else if(a[i-1]==b[j-1] || b[j-1]=='?')  curr[j] = prev[j-1];
    
            else if(b[j-1] =='*'){
                curr[j] = (prev[j] | curr[j-1]);
            }
            else curr[j] = false;
        }
        prev= curr;
    } 
    return curr[m];  
    
    // return solve(n,m,a,b,dp);
}
