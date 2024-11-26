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
int C = 30;
vector<vector<int>> jmp;


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>n>>q;
    jmp.resize(C,vector<int>(n+1,0));
    F(i,0,n) {
        cin>>jmp[0][i+1];
    }

    for (int i=1;i<C;i++) {
        for (int j=1;j<=n;j++) {
            jmp[i][j] = jmp[i-1][jmp[i-1][j]];
        }
    }

    while (q--) {
        int x,k; cin>>x>>k;
        for (int i=0;i<C;i++) {
            if (k&(1<<i)) {
                x=jmp[i][x];
            }
        }
        cout<<x<<'\n';
    }
      
}