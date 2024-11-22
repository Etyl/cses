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
vector<int> val;

void dfs(int x, int l) {
    for (int y:nxt[x]) {
        if (val[y]!=0) continue;
        val[y]=l;
        dfs(y,l);
    }
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
    val.resize(n,0);
    
    int count=0;
    vector<int> res;
    F(i,0,n) {
        if (val[i]==0) {
            val[i]=++count;
            dfs(i,count);
            res.push_back(i);
        }
    }
    cout<<sz(res)-1<<'\n';
    F(i,1,sz(res)) {
        cout<<res[i-1]+1<<' '<<res[i]+1<<'\n';
    }
}