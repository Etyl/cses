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
 
const int INF = 100'000'000;
int n,m;
vector<vector<int>> nxt;
vector<int> parent;
vector<int> dist;
pii start,finish;

bool djisktra(int begin, int end) {

    vector<bool> exp(n,false);
    priority_queue<pii, vector<pii>, greater<pii>> wait;
    dist[begin]=0;
    wait.emplace(0,begin);
    while (!wait.empty()) {
        int node, node_dist;
        tie(node_dist, node) = wait.top();
        wait.pop();

        if (exp[node]) continue;
        exp[node]=true;

        if (node==end) return true;
        for (int x:nxt[node]) {
            if (!exp[x] && dist[node]+1 < dist[x]) {
                parent[x]=node;
                dist[x]=dist[node]+1;
                wait.emplace(dist[x],x);
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    nxt.resize(n);
    F(i,0,m) {
        int x,y;cin>>x>>y;
        nxt[--y].push_back(--x);
        nxt[x].push_back(y);
    }
    parent.resize(n,-1);
    dist.resize(n,INF);

    if (djisktra(0,n-1)) {
        vector<int> res={n-1};
        while (res[sz(res)-1]!=0) res.push_back(parent[res[sz(res)-1]]);
        reverse(all(res));
        cout<<sz(res)<<'\n';
        for (int x:res) cout<<x+1<<" ";
        cout<<'\n';
    }
    else {
        cout<<"IMPOSSIBLE\n";
    }    
}