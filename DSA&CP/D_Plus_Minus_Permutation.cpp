#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find the least common multiple (LCM) of two numbers
long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}
void solve(){
    long long n,x,y;
    cin>>n>>x>>y;
    long long common = (n/(lcm(x,y)));
    long long d1 = floor(n/x) - common;
    long long d2 = floor(n/y) - common;
    // cout<<"common :"<<common<<" ,d1:"<<d1<<" ,d2:"<<d2<<endl;
    long long ans  = n*(n+1)/2 - d2*(d2+1)/2 - (n-d1)*(n-d1+1)/2;
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