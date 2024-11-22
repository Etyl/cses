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
vector<int> val;
vector<bool> visited;

bool dfs(int x, int v) {
    if (val[x]==-v) 
        return false;
    val[x]=v;
    visited[x]=true;
    bool res=true;
    for (int y:nxt[x]) {
        res = res && (val[y]!=v);
        if (visited[y]) continue;
        res = res && dfs(y, -v);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    nxt.resize(n);
    F(i,0,m) {
        int x,y; cin>>x>>y;
        nxt[--x].push_back(--y);
        nxt[y].push_back(x);
    }
    val.resize(n,0);
    visited.resize(n,false);
    F(i,0,n) {
        if (val[i]!=0) continue;
        if (!dfs(i,1)) {
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }

    for (int x:val) cout<<((x==1)?1:2)<<" ";
    cout<<"\n";
}