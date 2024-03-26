#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define int_min -1e18
#define int_max 1e16
#define mod 1000000007
//#define mod 998244353
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define rev(i,a,b)    for(int i=a;i>=b;i--)
#define arr(a,n)      rep(i,0,n) cin>>a[i]
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
/*#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;*/
 
//#define endl "\n"
class sove{
    public:
        int a,b,c;
};
bool compare(pair<int,int> p1,pair<int,int> p2)
{
    return p1.second<p2.second;
}
bool comp(pair<int,int> &p1,pair<int,int> &p2)
{
    return p1.second<p2.second;
}
 
bool comp1(pair<char,int> p1,pair<char,int> p2)
{
    if(p1.second==p2.second)
        return p1.first<p2.first;
    return p1.second<p2.second;
}
vector<int> isPalindrome(string s,int n)
{
    int prefix[s.size()]={0};
    for(int i=1;i<s.size();i++)
    {
        int j=prefix[i-1];
        while(j>0 && s[i]!=s[j])
            j=prefix[j-1];
        if(s[i]==s[j])
            j++;
        prefix[i]=j;
    }
    vector<int> v;
    rep(i,n+1,s.size())
        v.push_back(prefix[i]);
    return v;
}
int pwr(int x,int n,int mo)
{
    int res=1;
    if(n==0)
        return 1;
    if(n==1)
        return (x%mo);
    if(n%2)
        res=x%mo;
    int temp=pwr(x,n/2,mo);
    return (res*((temp*temp)%mo))%mo;
}
int modInverse(int a, int m)
{
    return pwr(a,m-2,m);
}
int nCrModp(int n, int r, int p)
{
    if (r > n - r)
        r = n - r;
    int C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j - 1]) % p;
    }
    return C[r];
}
int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	if (a < 0) a += mod;
	return a;
}
 
int mul(int a, int b) {
	return a * 1ll * b % mod;
}
vector<int> SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    vector<int> prie;
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            prie.push_back(p);
    return prie;
}
void permutation(vector<vector<int> >&permut,int si,int n,int *ans)
{
    if(si==n)
    {
        vector<int> temp(ans,ans+3);
        permut.push_back(temp);
        return;
    }
    for(int i=si;i<n;i++)
    {
        swap(ans[si],ans[i]);
        permutation(permut,si+1,n,ans);
        swap(ans[i],ans[si]);
    }
}
//int factor[10000001];
/*void primeFactors(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(factor[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
                {
                    if(factor[j]==0)
                        factor[j]=i;
                }
        }
    }
}*/
/*int filter(int n)
{
    map<int,int> m;
    while(n!=0)
    {
        //cout<<n<<" "<<factor[n]<<endl;
        if(factor[n]==0)
        {
            m[n]++;
            break;
        }
        m[factor[n]]++;
        n=n/factor[n];
    }
    int pro=1;
    map<int,int> :: iterator it=m.begin();
    while(it!=m.end())
    {
        //cout<<it->first<<" "<<it->second<<endl;
        if(it->second%2==1)
            pro=pro*it->first;
        it++;
    }
    return pro;
}*/
 
int checkParent(int v,vector<int> &parent)
{
    if(parent[v]==v)
        return v;
    return parent[v]=checkParent(parent[v],parent);
}
void dfs(int parent,int sv,vector<pair<int,int> > &ans,vector<vector<int> > &v)
{
    if(parent!=-1)
        ans.push_back({parent,sv});
    rep(i,0,v[sv].size())
    {
        if(v[sv][i]!=parent)
            dfs(sv,v[sv][i],ans,v);
    }
    return;
}
/*int tt[800008];
void build(int id,int l,int r,int *a)
{
    if(l==r)
    {
        tt[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id + 1,l,mid,a);
    build(2*id + 2,mid+1,r,a);
    tt[id]=max(tt[2*id +1],tt[2*id +2]);
    return;
}
int getAns(int l,int r,int qs,int qe,int id)
{
    if(qs>qe)
    {
       return INT_MIN;
    }
    if(l==qs && r==qe) return tt[id];
    int mid=(l+r)/2;
    int x=getAns(l,mid,qs,min(mid,qe),2*id +1);
    int y=getAns(mid+1,r,max(mid+1,qs),qe,2*id+2);
    return max(x,y);
}
void update(int id,int l,int r,int re,char a,char b)
{
    if(l==r && l==re)
    {
        if(a=='a') tt[id].a--;
        else if(a=='b') tt[id].b--;
        else tt[id].c--;
        if(b=='a') tt[id].a++;
        else if(b=='b') tt[id].b++;
        else tt[id].c++;
        return;
    }
    if(l>re || r<re) return;
    int mid=(l+r)/2;
    update(2*id + 1,l,mid,re,a,b);
    update(2*id + 2,mid+1,r,re,a,b);
    tt[id].a=tt[2*id +1].a + tt[2*id +2].a;
    tt[id].b=tt[2*id +1].b + tt[2*id +2].b;
    tt[id].c=tt[2*id +1].c + tt[2*id +2].c;
    return;
}*/
int cnt(int sv,vector<vector<pii> > &v,int p)
{
    int ans=0;
    rep(i,0,v[sv].size())
    {
        if(v[sv][i].first==p) continue;
       ans+=cnt(v[sv][i].first,v,sv);
    }
    return ans+1;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    arr(a,n);
    vector<int> presum(n),premax(n);
    presum[0]=a[0];
    premax[0]=a[0];
    rep(i,1,n) presum[i]=presum[i-1]+a[i],premax[i]=max(premax[i-1],a[i]);
    int b[k];
    arr(b,k);
    rep(i,0,k)
    {
        int x=upper_bound(premax.begin(),premax.end(),b[i])-premax.begin();
        if(x==0) cout<<0<<" ";
        else cout<<presum[x-1]<<" ";
    }
    cout<<endl;
}
signed main()
      {
          ios_base::sync_with_stdio(false);
          cin.tie(0);
          cout.tie(0);
          int t=1;
          cin>>t;
          while(t--) solve();
          return 0;
      }
 