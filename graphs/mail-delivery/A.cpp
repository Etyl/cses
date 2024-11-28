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
vector<ll> deg;

vector<ll> euler() {
    stack<ll> st;
    for (ll i = 1; i <= n; i++) {
        if (deg[i] % 2) {
            return {};
        }
    }
    vector<ll> path;
    st.push(1);
    while (st.size() > 0) {
        ll x = st.top();
        if (deg[x] == 0) {
            st.pop();
            path.push_back(x);
        }
        else {
            ll z = *(adj[x].begin());
            adj[x].erase(z);
            adj[z].erase(x);
            deg[x]--;
            deg[z]--;
            st.push(z);
        }
    }
    return path;
}

int main() {
    fastio;
    cin >> n >> m;
    adj.resize(n + 1);
    deg.resize(n + 1, 0);
    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        deg[x]++;
        deg[y]++;
    }

    vector<ll> path = euler();

    if (sz(path) != (m + 1))
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (auto &i : path)
    {
        cout << i << " ";
    }
}