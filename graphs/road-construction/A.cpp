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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

int n,m;

class UFS {
public:
	vector<int> parent;
    vector<int> size;
	UFS(int nn) {
        size.resize(nn+1,1);
		parent.resize(nn + 1);
		for (int i = 0; i < sz(parent); i++)
			parent[i] = i;
	}

	int merge(int x, int y) { // merge x and y into set, returns set size
		int px=find(x), py=find(y);
        parent[px] = py;
        size[py] += size[px];
        return size[py];
	}
	int find(int x) { // find parent root of x
		return x == parent[x] ? x : parent[x] = find(parent[x]);
	}
	bool together(int x, int y) { // test if x and y are in the same set
		return find(x) == find(y);
	}
};

int main() {
    fastio
    cin>>n>>m;
    UFS ufs = UFS(n);
    int res = n, size=1;
    while (m--) {
        int x,y;cin>>x>>y;
        if (!ufs.together(x,y)) {
            size = max(size,ufs.merge(x,y));
            res--;
        }
        cout<<res<<" "<<size<<'\n';
    }
}