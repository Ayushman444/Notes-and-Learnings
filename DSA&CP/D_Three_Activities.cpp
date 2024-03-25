#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,ans=0;
    cin>>n;

    vector<int> a(n),b(n),c(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    set<pair<int,int>> x,y;
    for(int i=0;i<n;i++){
        x.insert({b[i],i});
        y.insert({c[i],i});
    }
    for(int i=0;i<n;i++){
        x.erase({b[i],i});
        y.erase({c[i],i});

        if((*x.rbegin()).second == (*y.rbegin()).second){
            ans = max({ans,a[i]+(*(--x.end())).first+(*(--(--y.end()))).first,a[i]+(*(--y.end())).first+(*(--(--x.end()))).first});
        }else{
            ans = max(ans,a[i]+(*(--(x.end()))).first+(*(--(y.end()))).first);
        }
        x.insert({b[i],i});
        y.insert({c[i],i});
    }
    cout<<ans<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
return 0;
}