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
 
 
int n,q;
 
int LCA(int p,int q, const vector<vector<int>>& jmp, const vector<int>& L) {
	if(L[p] < L[q])
	swap(p, q);
	int diff = L[p] - L[q];
	for(int i = 20; i >= 0; i--) 
		if(diff & (1<<i)) 
		p = jmp[i][p];		
	if(p == q) return p;
 
	for (int i = 20; i >= 0; i--) {
		if (jmp[i][p] != jmp[i][q]) {
			p = jmp[i][p];
			q = jmp[i][q];
		}
	}
	return jmp[0][p];
}
 
int main() {
    cin>>n>>q;
    vector<vector<int>> nxt(n+1);
    F(i,0,n-1) {
        int x,y;cin>>x>>y;
        nxt[x].push_back(y);
        nxt[y].push_back(x);
    }
    vector<vector<int>> jmp(22,vector<int>(n+1,0));
    vector<int> L(n+1,0);
 
    function<void(int,int, int)> dfs = [&](int x,int parent, int l) {
        L[x]=l;
        for (int y:nxt[x]) {
            if (y==parent) continue;
            jmp[0][y]=x;
            dfs(y,x,l+1);
        }
    };
 
    dfs(1, -1, 0);
    for (int i=1;i<22;i++) {
        for (int j=1;j<=n;j++) {
            jmp[i][j] = jmp[i-1][jmp[i-1][j]];
        }
    }
 
    while (q--) {
        int a,b;cin>>a>>b;
        int boss = LCA(a,b,jmp,L);
        cout<<L[a]+L[b]-2*L[boss]<<'\n';
    }
}