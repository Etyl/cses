#include <bits/stdc++.h>
using namespace std;

#define pii pair<ll,ll>
#define ll long long
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define fi first
#define se second

int n;

pii dfs(vector<bool>& exp, const vector<vector<int>>& e, int x) {
    pii res = {0,x};
    exp[x]=true;
    for (int i:e[x]) {
        if (exp[i]) continue;
        pii r2 = dfs(exp,e,i);
        if (r2.first>=res.first) res={r2.first+1,r2.second};
    }
    return res;
}

int main() {
    cin>>n;
    vector<vector<int>> e(n);
    for(int i=0;i<n-1;i++) {
        int x,y;cin>>x>>y;
        e[--x].push_back(--y);
        e[y].push_back(x);
    }

    vector<bool> exp(n,false);
    pii res0 = dfs(exp,e,0);
    exp = vector<bool>(n,false);
    pii res = dfs(exp,e,res0.second);
    cout<<res.first<<'\n';
}