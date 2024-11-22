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

void dfsC(const vector<vector<int>>& e, vector<int>& childs, int x, int parent) {
    for (int i:e[x]) {
        if (i==parent) continue;
        dfsC(e,childs,i,x);
        childs[x] += childs[i]+1;
    }
}

ull dfs(const vector<vector<int>>& e,vector<int>& childs, int x, int parent) {
    ull res = 0;
    for (int i:e[x]) {
        if (i==parent) continue;
        res += childs[i]+dfs(e,childs,i,x)+1;
    }
    return res;
}

void dfsD(const vector<vector<int>>& e, vector<int>& childs, vector<ull>& dist, int x, int parent) {
    for (int i: e[x]) {
        if (i==parent) continue;
        dist[i] = dist[x]-childs[i]+(n-childs[i]-2);
        dfsD(e,childs,dist,i,x);
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

    int start=-1;
    for (int i=0;i<n;i++) {
        if (sz(e[i])<=1) {
            start=i;
            break;
        }
    }

    vector<int> childs(n,0);
    dfsC(e,childs,start,-1);

    vector<ull> dist(n,0);
    dist[start] = dfs(e,childs,start,-1);
    dfsD(e,childs,dist,start,-1);

    for (ull x:dist) cout<<x<<" ";
    cout<<'\n';
}