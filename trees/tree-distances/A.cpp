#include <bits/stdc++.h>
using namespace std;

#define pii pair<ll,ll>
#define ll long long
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define fi first
#define se second
#define F(i,k,n) for(int i=k;i<n;i++)

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

void dfsD(const vector<vector<int>>& e, vector<int>& d, int x, int parent) {
    for (int i:e[x]) {
        if (i==parent) continue;
        d[i] = d[x]+1;
        dfsD(e,d,i,x);
    }
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
    pii res1 = dfs(exp,e,0);
    exp = vector<bool>(n,false);
    pii res2 = dfs(exp,e,res1.second);
    
    vector<int> d1(n,0),d2(n,0);
    dfsD(e,d1,res1.second,-1);
    dfsD(e,d2,res2.second,-1);
    F(i,0,n) cout<<max(d1[i],d2[i])<<" ";
    cout<<'\n';
}