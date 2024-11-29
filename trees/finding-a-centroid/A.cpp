#include <bits/stdc++.h>
using namespace std;
 
#define pii pair<ll,ll>
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define fi first
#define se second
#define F(i,k,n) for(int i=k;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n;
vector<vector<ll>> adj;
vector<ll> subCount;
ll res=0;

void dfs(ll x, ll parent) {
    subCount[x]=1;
    for (ll y:adj[x]) {
        if (y==parent) continue;
        dfs(y,x);
        subCount[x]+=subCount[y];
    }
}

void dfs2(int x) {
    for (ll y:adj[x]) {
        if (subCount[y]>n/2) {
            ll total = subCount[x];
            subCount[x] = total - subCount[y];
            subCount[y] = total;
            dfs2(y);
            return;
        }
    }
    res = x;
}

int main() {
    fastio;
    cin>>n;
    adj.resize(n+1);
    F(i,0,n-1) {
        ll x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    subCount.resize(n+1);
    dfs(1,0);
    dfs2(1);
    cout<<res<<'\n';    
}