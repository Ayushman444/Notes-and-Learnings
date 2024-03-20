int lcs(string s, string t)
{
	int n = s.size();
	int m = t.size();
	// vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	vector<int> prev(m+1,0),curr(m+1,0);
	
	for(int j=0;j<=m;j++) prev[j]=0;
	for(int i1 = 1;i1<=n;i1++){
		for(int i2=1;i2<=m;i2++){

			//		matching case
				if(s[i1-1]==t[i2-1]){
					curr[i2] = 1 + prev[i2-1];
				}

			//  	not matching case
				else curr[i2] = max(prev[i2],curr[i2-1]);
		}
		prev=curr;
	}
		
	

	return prev[m];
}