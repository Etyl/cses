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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;
    vector<vector<int>> nxt(n+1);
    F(i,0,n-1) {
        int x,y;cin>>x>>y;
        nxt[x].push_back(y);
        nxt[y].push_back(x);
    }
    vector<vector<int>> jmp(22,vector<int>(n+1,0));
    vector<int> L(n+1,0);
    vector<int> parent(n+1,0);

    function<void(int,int, int)> dfs = [&](int x,int p, int l) {
        L[x]=l;
        parent[x]=p;
        for (int y:nxt[x]) {
            if (y==p) continue;
            jmp[0][y]=x;
            dfs(y,x,l+1);
        }
    };

    dfs(1, 0, 0);
    for (int i=1;i<22;i++) {
        for (int j=1;j<=n;j++) {
            jmp[i][j] = jmp[i-1][jmp[i-1][j]];
        }
    }

    vector<int> pref(n+1,0);
    while (q--) {
        int a,b;cin>>a>>b;
        int boss = LCA(a,b,jmp,L);
        pref[a]++; pref[b]++;
        pref[boss]--; pref[parent[boss]]--;
    }

    vector<int> res(n+1,0);
    function<void(int)> preSum = [&](int x) {
        res[x] = pref[x];
        for (int y:nxt[x]) {
            if (y==parent[x]) continue;
            preSum(y);
            res[x] += res[y];
        }
    };
    preSum(1);

    for (int i=1;i<=n;i++) {
        cout<<res[i]<<' ';
    }
    cout<<'\n';
}