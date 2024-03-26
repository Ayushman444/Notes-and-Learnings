#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1) cout<<1<<endl;
    else if(n==2){
        if(a[0]==a[1]) cout<<1<<endl;
        else cout<<2<<endl;
    }
    else {
        int ans = n;
        int i = 0,j=1,k=2;
        while(k<n){
            if((a[i]<=a[j] && a[j]<=a[k])||(a[i]>=a[j] && a[j]>=a[k])){
                ans--;
                j++;
                k++;
            }else{
                i=j;
                j++;
                k++;
            }
        }
        // cout<<"i is:"<<i<<" j is : "<<j<<endl;
        if(a[i]==a[j]) ans--;
        cout<<ans<<endl;
    }
    

}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
return 0;
}