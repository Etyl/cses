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

ll n, m;
vector<set<ll>> adj;
vector<ll> indeg,outdeg;

vector<ll> euler() {
    stack<ll> st;
    for (ll i = 2; i < n; i++) { // for path with 0, n-1 the ends
        if (indeg[i] != outdeg[i]) { // indeg[i] != outdeg[i]
            return {};
        }
    }
    
    if (((outdeg[1] - indeg[1]) != 1) || ((outdeg[n] - indeg[n]) != -1))
        return {};

    vector<ll> path;
    st.push(1);
    while (st.size() > 0) {
        ll x = st.top();
        if ((indeg[x] == 0) && (outdeg[x] == 0)) { // ((indeg[x] == 0) && (outdeg[x] == 0))
            st.pop();
            path.push_back(x);
        }
        else {
            ll z = *(adj[x].begin());
            adj[x].erase(z);
            outdeg[x]--; // outdeg[x]--; 
            indeg[z]--; // indeg[z]--;
            st.push(z);
        }
    }
    return path;
}

int main() {
    fastio;
    cin >> n >> m;
    adj.resize(n + 1);
    indeg.resize(n + 1, 0);
    outdeg.resize(n + 1, 0);
    for (ll i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        adj[x].insert(y);
        outdeg[x]++;
        indeg[y]++;
    }

    vector<ll> path = euler();
    reverse(all(path));

    if (sz(path) != m+1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (auto x : path)
    {
        cout << x << " ";
    }
}