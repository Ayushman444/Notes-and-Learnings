#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n,m;
    cin>>n>>m;
    vector<vector<long long>> a(n,vector<long long>(m,0));
    for(long long i=0;i<n;i++){
        for(long long j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    long long ans = 0;
    for(long long j=0;j<m;j++){
        vector<long long> temp;
        for(long long i=0;i<n;i++){
            temp.push_back(a[i][j]);
            // cout<<a[i][j]<<" ";
        }
        // cout<<endl;
        sort(temp.begin(),temp.end(),greater<long long>());
        long long l = 0;
        long long r = n-1;
        for(long long i=0;i<n;i++){
            ans += (temp[i]*(r-l));
            r--;
            l++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    long long t;
    cin>>t;
    while(t--) solve();
return 0;
}