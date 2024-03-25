#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n,x,y;
    cin>>n>>x>>y;
    long long common = (n/(x*y));
    long long d1 = floor(n/x) - common;
    long long d2 = floor(n/y) - common;
    long long ans  = n*(n+1)/2 - d1*(d1+1)/2 + (n-d2)*(n-d2+1)/2;
    cout<<ans<<endl;

    
}
int main(){
    long long t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
return 0;
}