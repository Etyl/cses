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
vector<vector<char>> dirs;
pii start,finish;

void bfs(int x, int y) {
    deque<pii> wait;
    wait.push_back({x,y});
    while(sz(wait)>0) {
        pii p=wait.front();
        wait.pop_front();
        int i=p.fi,j=p.se;
        
        if (i>0 && matrix[i-1][j]=='.' && dirs[i-1][j]==' ') {
            dirs[i-1][j]='D';
            wait.push_back({i-1,j});
        }
        if (i<n-1 && matrix[i+1][j]=='.' && dirs[i+1][j]==' ') {
            dirs[i+1][j]='U';
            wait.push_back({i+1,j});
        }
        if (j>0 && matrix[i][j-1]=='.' && dirs[i][j-1]==' ') {
            dirs[i][j-1]='R';
            wait.push_back({i,j-1});
        }
        if (i<m-1 && matrix[i][j+1]=='.' && dirs[i][j+1]==' ') {
            dirs[i][j+1]='L';
            wait.push_back({i,j+1});
        }
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    F(i,0,n) {
        vector<char> l(m);
        F(j,0,m) {
            cin>>l[j];
            if (l[j]=='A') {start={i,j}; l[j]='.';}
            if (l[j]=='B') {finish={i,j}; l[j]='.';}
        }
        matrix.push_back(l);
    }
    dirs.resize(n,vector<char>(m,' '));
    bfs(finish.fi,finish.se);
    dirs[finish.fi][finish.se] = ' ';

    vector<char> res;
    int i=start.first, j=start.second;
    while (dirs[i][j] != ' ') {
        res.push_back(dirs[i][j]);
        if (dirs[i][j]=='R') j++;
        else if (dirs[i][j]=='L') j--;
        else if (dirs[i][j]=='U') i--;
        else if (dirs[i][j]=='D') i++;
    }
    if (i==finish.fi && j==finish.se) {
        cout<<"YES\n"<<sz(res)<<'\n';
        for (char c:res)cout<<c;
        cout<<'\n';
    }
    else {
        cout<<"NO\n";
    }
}