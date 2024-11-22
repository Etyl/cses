#include <bits/stdc++.h>
using namespace std;

#define pii pair<ll,ll>
#define ll long long
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define fi first
#define se second

int n;


int main() {
    cin>>n;
    vector<int> x(n);
    for (int i=0;i<n;i++) cin>>x[i];
    set<int> res= {0};
    for (int k:x) {
        vector<int> res2;
        for (int l:res) res2.push_back(l+k);
        for (int l:res2) res.insert(l);
    }    
    res.erase(0);
    cout<<sz(res)<<'\n';
    for (int k:res) cout<<k<<' ';
    cout<<'\n';
}