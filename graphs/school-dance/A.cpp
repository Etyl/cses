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

const ll INF = LLONG_MAX;
int n,m,k,N;
vector<vector<ll>> capacity;
vector<vector<int>> adj; // adjacency (undirected)
vector<bool> part;
vector<pll> edges;

ll bfs(int s, int t, vector<int>& parent) {
    fill(all(parent), -1);
    parent[s] = -2;
    queue<pll> q;
    q.push({s, INF});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0LL;
}

ll maxflow(int s, int t) {
    ll flow = 0;
    vector<int> parent(N);

    for (ll new_flow=bfs(s, t, parent); new_flow>0; new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        ll cur = t;
        while (cur != s) {
            ll prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

void cut(int x) {
    part[x]=true;
    for (int y: adj[x]) {
        if (!part[y] && (capacity[x][y]>0)) cut(y);
    }
}

int main() {
    fastio
    cin>>n>>m>>k;
    N = n+m+2;
    adj.resize(N);
    capacity.resize(N,vector<ll>(N,0));
    edges.resize(k);
    F(i,0,k) {
        int a,b; cin>>a>>b;
        edges[i] = {a,n+b};
        if (capacity[a][b]==0 && capacity[b][a]==0) {
            adj[a].push_back(n+b);
            adj[n+b].push_back(a);
        }
        capacity[a][b+n]=1;
    }
    F(i,1,n+1) {
        adj[0].push_back(i);
        adj[i].push_back(0);
        capacity[0][i]=1;
    }
    F(i,n+1,N-1) {
        adj[N-1].push_back(i);
        adj[i].push_back(N-1);
        capacity[i][N-1]=1;
    }
    maxflow(0,N-1);
    set<pll> res;
    for (pll p: edges) {
        if (capacity[p.fi][p.se]==0) res.insert(p);
    }

    cout<<sz(res)<<'\n';
    for (pll p:res) cout<<p.fi<<" "<<p.se-n<<'\n';
}