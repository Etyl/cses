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


int main() {
    string s;cin>>s;
    int n=sz(s);

    vector<int> z(n,0);    


    vector<int> ne(s.size(), -1); // next[], if par[i] not matched, jump to i = ne[i]
    ne[0] = -1;
    for (int p = ne[0], i = 1; i < s.length(); i++) {
        while (p >= 0 && s[p+1] != s[i])
            p = ne[p];
        if (s[p+1] == s[i])
            p++;
        ne[i] = p;
    }


}