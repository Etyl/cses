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


int n;
vector<int> nxt, dist;
vector<bool> visited;


void dfsCycle(int x, int target, int val) {
    if (x==target) {
        dist[x]=val;
    }
    else {
        dfsCycle(nxt[x],target,val+1);
        dist[x]=dist[target];
    }
}

void dfs(int x, unordered_set<int>& exp) {
    visited[x]=true;
    exp.insert(x);
    if (exp.find(nxt[x])!=exp.end()) {
        dfsCycle(nxt[x],x, 1);
    }
    else if (visited[nxt[x]]) {
        dist[x] = dist[nxt[x]]+1;
    }
    else {
        dfs(nxt[x], exp);
        if (dist[x]==-1) dist[x]=dist[nxt[x]]+1;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>n;
    nxt.resize(n+1);
    F(i,0,n) {
        cin>>nxt[i+1];
    }

    dist.resize(n+1,-1);
    visited.resize(n+1,false);
    F(x,1,n+1) {
        if (dist[x]==-1) {
            unordered_set<int> exp;
            dfs(x, exp);
        }
        cout<<dist[x]<<" ";
    }
    cout<<'\n';
}