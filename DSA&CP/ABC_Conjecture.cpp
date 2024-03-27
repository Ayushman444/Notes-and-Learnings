#include <bits/stdc++.h>
using namespace std;

void solve(){
    // cout<<"----------"<<endl;
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    set<int> bindex;
    set<int> ac;
    set<int> ca;
    for(int i=0;i<n;i++){
        if(a[i]=='b'){
            if(b[i]=='b'){
                bindex.insert(i);
            }else{
                cout<<"No"<<endl;
                return;
            }
        }
        if(a[i]=='a' && b[i] == 'c'){
            ac.insert(i);
        }else if(a[i]=='c' && b[i] == 'a'){
            ca.insert(i);
        }
    }
    
   for (auto index : ac) {
        auto it = bindex.lower_bound(index);
        // cout<<"index is" <<index<<endl;
        if (it == bindex.end() || (ca.empty() || *it > *ca.begin())) {   
            cout << "No" << endl;
            return;
        }
        bindex.erase(it);
        ac.erase(index);
        ca.erase(*ca.begin());  
        if(ac.empty()) break;
    }

    if (ac.empty() && ca.empty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
	int t;
	cin>>t;
	while(t--) solve();
    return 0;
}
