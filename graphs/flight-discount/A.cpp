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
 
const ll INF = LLONG_MAX;

int n,m;
vector<vector<pll>> nxt;
vector<vector<pll>> nxtR;
vector<ll> dist;
vector<ll> distR;

void dijkstra(int start, vector<ll>& dist, vector<vector<pll>>& nxt) {
    dist.resize(n+1,INF);
    dist[start]=0;
    vector<bool> visited(n+1,false);
    priority_queue<pll, vector<pll>, greater<pll>> wait;
    wait.emplace(0,start);
    while (!wait.empty()) {
        ll node, d;
        tie(d,node) = wait.top();
        wait.pop();

        if (visited[node]) continue;
        visited[node]=true;

        for (pll p: nxt[node]) {
            if (!visited[p.fi] && dist[node]+p.se < dist[p.fi]) {
                dist[p.fi] = dist[node]+p.se;
                wait.emplace(dist[p.fi],p.fi);
            }
        }
    }
}

ll res=INF;
vector<bool> visited;
void dfs(int node) {
    visited[node]=true;
    for (pll p: nxt[node]) {
        res = min(res, dist[node]+p.second/2+distR[p.fi]);
        if (visited[p.fi]) continue;
        dfs(p.fi);
    }
}

int main() {
    cin>>n>>m;

    nxt.resize(n+1);
    nxtR.resize(n+1);
    F(i,0,m) {
        int a,b,w; cin>>a>>b>>w;
        nxt[a].push_back({b,w});
        nxtR[b].push_back({a,w});
    }

    dijkstra(1,dist,nxt);
    dijkstra(n,distR,nxtR);
    visited.resize(n+1,false);
    dfs(1);
    
    cout<<res<<'\n';
}