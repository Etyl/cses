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
vector<bool> visited;
vector<pii> solutions;

void dfs(int x) {
    visited[x]=true;
    for (int y:nxt[x]) {
        if (y==parent[x]) continue;
        if (visited[y]) {
            solutions.push_back({x,y});
            continue;
        }
        parent[y]=x;
        dfs(y);
    }
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
    parent.resize(n,-1);
    visited.resize(n,false);
    solutions.clear();
    F(i,0,n) {
        if (visited[i]) continue;
        dfs(i);
    }

    if (sz(solutions)==0) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    else {
        int x,y;
        tie(x,y)=solutions[0];
        vector<int> left={x},right={y};
        while (parent[left[sz(left)-1]]!=-1) left.push_back(parent[left[sz(left)-1]]);
        while (parent[right[sz(right)-1]]!=-1) right.push_back(parent[right[sz(right)-1]]);
        reverse(all(left)); reverse(all(right));
        vector<int> l2,r2;
        int i;
        for (i=0;i<min(sz(left),sz(right));i++) {
            if (left[i]==right[i]) continue;
            l2.push_back(left[i]);
            r2.push_back(right[i]);
        }
        F(j,i,sz(left)) l2.push_back(left[j]);
        F(j,i,sz(right)) r2.push_back(right[j]);
        
        vector<int> path;
        if (sz(left)>0) path = l2;
        else path=r2;
        path.push_back(parent[path[0]]);
        reverse(all(path));
        path.push_back(parent[path[sz(path)-1]]);
        
        cout<<sz(path)<<"\n";
        for (int x:path) cout<<x+1<<" ";
        cout<<'\n';
    }
}