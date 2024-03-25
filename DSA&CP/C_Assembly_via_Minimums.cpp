#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    map<int,int> a;
    for(int i=0;i<n*(n-1)/2;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    vector<int> ans;
    int t = n-1;
    while(a.size()!=0){
        auto it = a.begin();
        ans.push_back(it->first);
        it->second = it->second-t;
        if (it->second <= 0) {
            a.erase(it); // Removing elements with zero or negative frequency
        }
        t--;
    }
    ans.push_back(1e9);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

   


}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
return 0;
}