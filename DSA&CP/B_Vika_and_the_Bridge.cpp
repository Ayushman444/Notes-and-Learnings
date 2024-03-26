#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> prev(k + 1, -1);
    map<int, multiset<int>> m;
    for (int i = 0; i < n; i++) {
        int curr = a[i];
        int steps = i - prev[curr] - 1;
        prev[curr] = i;
        m[curr].insert(steps);
    }
    for (int i = 1; i <= k; i++) {
        m[i].insert(n - prev[i] -1);
    }
    int minMax = INT_MAX;
    for (auto &pair : m) {
        auto &ms = pair.second;
        if (!ms.empty()) {
            auto it = ms.end();
            it--;
            int maxVal = *it;
            ms.erase(it); // Erase the largest element
            ms.insert(maxVal / 2); // Insert the halved value
            int currMinMax = *ms.rbegin(); // Getting the new maximum
            minMax = min(minMax, currMinMax); // Updating the minimum among all maximums
        }
    }
    cout << minMax << endl;
}


int main(){
    int t;
    cin>>t;
    while(t--) solve();
return 0;
}