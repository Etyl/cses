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
vector<ll> val;
vector<vector<int>> nxt; 
vector<int> start;
vector<int> endv;
vector<int> ordered_nodes;
int timer = 0;

void euler_tour(int at, int prev) {
	start[at] = timer;
    ordered_nodes[timer++] = at;
	for (int n : nxt[at]) {
		if (n != prev) euler_tour(n, at);
	}
	endv[at] = timer;
}

// get the previous and next power of 2
unsigned int prev2(unsigned int n) {
    return 1U << (31 - __builtin_clz(n));
}
unsigned int next2(unsigned int n) {
    return n == 0 ? 1 : 1U << (32 - __builtin_clz(n - 1));
}

class SegTree {
private:
    vector<ll> tree;
    int n;
    void build(const vector<ll>& arr,int node, int i, int j) {
        if (i==j) {
            tree[node]=arr[i];
            return;
        }
        int left=2*node,right=2*node+1;
        build(arr,left,i,-((-i-j)/2));
        build(arr,right,-((-j-i)/2)+1,j);
        tree[node]= tree[left]+tree[right];
    }

    ll query_aux(int i, int j) {
        if (i>j) return 0;
        if (i==j) return tree[i];
        ll res=tree[i]+tree[j];
        int i0=i,j0=j;
        i/=2;j/=2;
        while (i!=j) {
            if (2*i+1!=i0) res +=tree[2*i+1];
            if (2*j!=j0) res += tree[2*j];
            i0=i,j0=j,i/=2;j/=2;
        }
        return res;
    }

    void update_aux(int node) {
        tree[node]=tree[2*node]+tree[2*node+1];
        if (node<=1) return;
        update_aux(node/2);
    }
    
public:
    SegTree(vector<ll> arr) {
        this->n = sz(arr);
        arr.resize(next2(n));
        tree.resize(2*sz(arr)+1);
        build(arr, 1, 0, sz(arr)-1);
    }

    ll query(pll q) {
        return query_aux((next2(n)+q.first), (next2(n)+q.second));
    }

    void update(pll q) {
        tree[next2(n)+q.first]=q.second;
        update_aux((next2(n)+q.first)/2);
    }

};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;
    val.resize(n);
    F(i,0,n) cin>>val[i];

    nxt.resize(n+1);
    F(i,0,n-1) {
        int x,y;cin>>x>>y;
        nxt[--x].push_back(--y);
        nxt[y].push_back(x);
    }

    start.resize(n);
    endv.resize(n);
    ordered_nodes.resize(n);
    euler_tour(0,-1);
    
    vector<ll> ordered_vals(n);
    F(i,0,n) ordered_vals[i] = val[ordered_nodes[i]];

    SegTree tree = SegTree(ordered_vals);

    while (q--) {
        int type;cin>>type;
        if (type==1) {
            int s,x;cin>>s>>x;
            tree.update({start[--s],x});
        }
        else {
            int s;cin>>s;
            cout<<tree.query({start[--s],endv[s]})<<"\n";
        }

    }
}