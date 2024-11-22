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

void dfs(int k, vector<vector<int>>& nei, vector<vector<int>>& dp, vector<bool>& exp) {
    exp[k]=true;
    for (int x:nei[k]) {
        if (exp[x]) continue;
        dfs(x,nei,dp, exp);
        dp[0][k] += max(dp[0][x], dp[1][x]);
        dp[1][k] = max(dp[1][k], min(0,dp[0][x]-dp[1][x]));
    }
    dp[1][k] += dp[0][k];
    dp[1][k]++;
}


int main() {
    int n;cin>>n;
    vector<vector<int>> nei(n);
    F(i,0,n-1) {
        int x,y; cin>>x>>y;x--;y--;
        nei[x].push_back(y);
        nei[y].push_back(x);
    }
    vector<vector<int>> dp(2,vector<int>(n,0));
    F(i,0,n) dp[1][i]=-INF;
    vector<bool> exp(n,false);
    dfs(0,nei,dp,exp);
    cout<<max(dp[0][0],dp[1][0])<<"\n";
}