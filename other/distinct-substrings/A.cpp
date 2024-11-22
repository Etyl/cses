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

constexpr ull g=1000'000+3;

template<ull Base, ull Exp>
struct FastPower {
    static constexpr ull half = FastPower<Base, Exp / 2>::value;
    static constexpr ull value = (Exp % 2 == 0) ? half * half : Base * half * half;
};

template<ull Base>
struct FastPower<Base, 0> {
    static constexpr ull value = 1;
};


int main() {
    string s;cin>>s;
    set<ull> strs;
    ull hash = 0;
    ull g1 = FastPower<g, ~0ULL>::value;
    F(i,0,sz(s)) {
        ull currentG = 1;
        F(j,i,sz(s)) {
            hash = hash + s[j]*currentG;
            currentG *= g;
            strs.insert(hash);
        }
        hash = 0;
    }
    cout<<sz(strs)<<'\n';
}