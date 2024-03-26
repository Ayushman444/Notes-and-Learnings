#include<bits/stdc++.h>
using namespace std;
int findMaxInRange(vector<int>& vec, int l, int r) {
    

    int maxElement = vec[l]; 

    // Loop through the range [l+1, r] to find the maximum element
    for (int i = l + 1; i <= r; ++i) {
        if (vec[i] > maxElement) {
            maxElement = vec[i];
        }
    }

    return maxElement;
}


int findMinInRange(vector<int>& vec, int l, int r) { 

    int minElement = vec[l]; 
    for (int i = l + 1; i <= r; ++i) {
        if (vec[i] < minElement) {
            minElement = vec[i];
        }
    }
    return minElement;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mini = 1;
    int maxi = n;
    int l = 0,r = n-1;
    while(l<r){
        if( a[r]!=mini && a[r]!=maxi && a[l]!=mini && a[l]!=maxi){
            cout<<l+1<<" "<<r+1<<endl;
            return;
        }
        if(a[l]==mini){
            l++;
            // mini = findMinInRange(a,l,r);
            mini++;
        }
        else if(a[l]==maxi){
            l++;
            // maxi = findMaxInRange(a,l,r);
            maxi--;
        }
        if(a[r]==mini){
            r--;
            // mini = findMinInRange(a,l,r);
            mini++;
        }
        else if(a[r]==maxi){
            r--;
            // maxi = findMaxInRange(a,l,r);
            maxi--;
        }
    }
    cout<<-1<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
return 0;
}