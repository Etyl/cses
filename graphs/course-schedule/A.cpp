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


int n,m;
vector<vector<int>> nxt;
vector<bool> visited;
vector<int> tsort, deg;



int main() {
    cin>>n>>m;
    nxt.resize(n+1);
    deg.resize(n+1,0);
    F(i,0,m) {
        int a,b;cin>>a>>b;
        nxt[a].push_back(b);
        deg[b]++;
    }

    vector<int> wait;
    F(i,1,n+1) {
        if (deg[i]==0) wait.push_back(i);
    }

    visited.resize(n+1,false);
    while (!wait.empty()) {
        int x=wait.back();
        wait.pop_back();

        tsort.push_back(x);
        for (int y:nxt[x]) {
            deg[y]--;
            if (deg[y]==0 && !visited[y]) {
                wait.push_back(y);
                visited[y]=true;
            }
        }
    }

    if (sz(tsort)==n) {
        for (int x:tsort) cout<<x<<' ';
        cout<<'\n';
    }
    else {
        cout<<"IMPOSSIBLE\n";
    }
    
    
    
}