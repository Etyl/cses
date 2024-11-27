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
vector<bool> vis;
vector<int> node_order;
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
    for(int y: adj_t[x]){
        if (!vis[y]) dfs_t(y);
    }
}

void kosarajuSCC(){
    int scc_count= 0;
    node_order.clear();
    vis.resize(n+1,false);

    for(int i= 1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    
    fill(all(vis), false);
    vector<int> res;
    
    for(int i= node_order.size()-1; i>= 0; i--){
        if(!vis[node_order[i]]){
            dfs_t(node_order[i]);
            scc_count++;
            res.push_back(node_order[i]);
            if (sz(res)>=2) {
                cout<<"NO\n";
                cout<<res[1]<<" "<<res[0]<<'\n';
                return;
            }
        }    
    }
    cout <<"YES";
    // return scc_count;
}

int main() {
    fastio
    cin>>n>>m;
    adj.resize(n+1);
    adj_t.resize(n+1);
    F(i,0,m) {
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj_t[y].push_back(x);
    }
    kosarajuSCC();
}