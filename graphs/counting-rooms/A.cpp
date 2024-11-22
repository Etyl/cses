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
 

int n,m;
vector<vector<char>> matrix;
vector<vector<int>> val;

void dfs(int i, int j, int l) {
    F(p,i-1,i+2) {
        if (p>=0 && p<n && val[p][j]==0 && matrix[p][j]=='.') {
            val[p][j]=l;
            dfs(p,j,l);
        }
    }
    F(q,j-1,j+2) {
        if (j>=0 && j<m && val[i][q]==0 && matrix[i][q]=='.') {
            val[i][q]=l;
            dfs(i,q,l);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    F(i,0,n) {
        vector<char> l(m);
        F(j,0,m) cin>>l[j];
        matrix.push_back(l);
    }
    val.resize(n,vector<int>(m,0));
    
    int count=0;
    F(i,0,n) {
        F(j,0,m) {
            if (matrix[i][j]=='.' && val[i][j]==0) dfs(i,j,++count);
        }
    }
    cout<<count<<'\n';
}