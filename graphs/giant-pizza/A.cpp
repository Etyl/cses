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
vector<int> node_order;
vector<int> scc; // scc[i] is the strongly connected component of node i, topologically ordered
vector<vector<int>> adj, adj_t;

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

int T(int x) {
    return (x+m+1)%N;
}

int main() {
    fastio
    cin>>n>>m;
    N = 2*m+2;
    adj.resize(N);
    adj_t.resize(N);
    F(i,0,n) {
        char ac,bc; int a,b; cin>>ac>>a>>bc>>b;
        if (ac=='-') a=T(a);
        if (bc=='-') b=T(b);
        adj[T(a)].push_back(b);
        adj[T(b)].push_back(a);
        adj_t[b].push_back(T(a));
        adj_t[a].push_back(T(b));
    }

    kosarajuSCC();

    F(x,1,m+1) {
        if (scc[x]==scc[T(x)]) {
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }

    F(x,1,m+1) {
        cout<< ((scc[x]>scc[T(x)]) ? "+ " : "- ");
    }
    cout<<'\n';
}