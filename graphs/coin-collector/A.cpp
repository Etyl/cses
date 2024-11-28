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

int n,m,N;
int scc_count=0;
vector<bool> vis;
vector<ll> node_order, val, val_scc;
vector<int> scc; // scc[i] is the strongly connected component of node i, topologically ordered
vector<vector<int>> adj, adj_t;
vector<set<int>> adj_scc;

void dfs(int x){
    vis[x]= true;    
    for(int y: adj[x]){
        if (!vis[y]) dfs(y);
    }
    node_order.push_back(x);
}

void dfs_t(int x){
    vis[x]= true;
    scc[x]= scc_count;
    for(int y: adj_t[x]){
        if (!vis[y]) dfs_t(y);
    }
}

void kosarajuSCC(){
    scc_count = 0;
    node_order.clear();
    vis.resize(N,false);
    scc.resize(N, -1);

    F(i,0,N) {
        if(!vis[i]){
            dfs(i);
        }
    }
    fill(all(vis), false);
    
    for(int i= node_order.size()-1; i>= 0; i--){
        if(!vis[node_order[i]]){
            dfs_t(node_order[i]);
            scc_count++;
        }
    }
}

void createDAG() {
    adj_scc.resize(scc_count);
    val_scc.resize(scc_count,0);
    F(x,1,n+1) {
        val_scc[scc[x]]+=val[x];
        for (int y:adj[x]) {
            if (scc[x] != scc[y]) adj_scc[scc[x]].insert(scc[y]);
        }
    }
}

vector<ll> res_scc;
void dfsRes(int x, vector<bool>& exp) {
    exp[x]=true;
    ll res=0;
    for (int y:adj_scc[x]) {
        if (!exp[y]) dfsRes(y,exp); 
        res = max(res,res_scc[y]);
    }
    res_scc[x] = res+val_scc[x];
}

int T(int x) {
    return (x+m+1)%N;
}

int main() {
    fastio
    cin>>n>>m;
    N=n+1;
    adj.resize(n+1);
    adj_t.resize(n+1);
    val.resize(n+1);
    F(i,1,n+1) cin>>val[i];
    F(i,0,m) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj_t[b].push_back(a);
    }

    kosarajuSCC();
    createDAG();
    ll res=0;
    vector<bool> exp(scc_count,false);
    res_scc.resize(scc_count);
    F(x,0,scc_count) {
        if (!exp[x]) dfsRes(x,exp);
        res = max(res,res_scc[x]);
    }
    cout<<res<<'\n';
}