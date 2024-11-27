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

void dfs_t(int x, vector<int>& res, int val){
    vis[x]= true;
    res[x]=val;  
    for(int y: adj_t[x]){
        if (!vis[y]) dfs_t(y, res,val);
    }
}

void kosarajuSCC(){
    node_order.clear();
    vis.resize(n+1,false);

    for(int i= 1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    
    fill(all(vis), false);
    vector<int> res(n+1,0);
    int val=0;
    
    for(int i= node_order.size()-1; i>= 0; i--){
        if(!vis[node_order[i]]){
            dfs_t(node_order[i], res, ++val);  
        }    
    }
    
    cout<<val<<'\n';
    F(i,1,n+1) cout<<res[i]<<" ";
    cout<<'\n';
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