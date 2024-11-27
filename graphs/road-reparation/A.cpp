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

int n,m;
vector<vector<pll>> adj;
vector<bool> visited;

ll prim() {
    priority_queue<pll, vector<pll>, greater<pll>> wait;
    visited.resize(n+1,false);
    visited[1]=true;
    for (pll p:adj[1]) {
        wait.emplace(p.se,p.fi);
    }
    ll res=0;
    while (!wait.empty()) {
        auto it=wait.top();
        wait.pop();
        if (visited[it.se])
            continue;
        
        visited[it.se]=true;
        res += it.fi;
        for (pll p:adj[it.se]) {
            if (!visited[p.fi]) wait.emplace(p.se,p.fi);
        }
    }
    return res;
}

int main(){
    fastio
    cin>>n>>m;
    adj.resize(n+1);
    F(i,0,m) {
        ll a,b,w;cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    ll res=prim();
    F(i,1,n+1) {
        if (!visited[i]) {
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    cout<<res<<'\n';
}
