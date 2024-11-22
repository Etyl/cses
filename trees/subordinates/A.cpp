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


void dfs(vector<vector<int>>& childs, vector<int>& sub, int i) {
    int res = 0;
    for (int x:childs[i]) {
        res++;
        dfs(childs,sub,x);
        res += sub[x];
    }
    sub[i] = res;
}

int main() {
    int n;cin>>n;
    vector<vector<int>> childs(n);
    F(i,0,n-1) {
        int x;cin>>x;
        childs[x-1].push_back(i+1);
    }
    vector<int> sub(n,0);
    dfs(childs,sub,0);
    for (int x:sub) cout<<x<<" ";
    cout<<'\n';
}