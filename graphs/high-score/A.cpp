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
 
const ll INF = 10'000'000'000;

vector<vector<ll>> edges;
vector<vector<int>> nxt;
vector<vector<int>> nxtR;

int n,m;

vector<ll> dist;
vector<bool> affected;


void bellman() {
    dist.resize(n+1,-INF);
    dist[1]=0;
    for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < sz(edges); j++) {
			if (dist[edges[j][0]] + edges[j][2] > dist[edges[j][1]])
				dist[edges[j][1]] = dist[edges[j][0]] + edges[j][2];
		}
	}
}



int main() {
    cin>>n>>m;
    edges.resize(m);
    nxt.resize(n+1);
    nxtR.resize(n+1);
    F(i,0,m) {
        vector<ll> e(3);
        cin>>e[0]>>e[1]>>e[2];
        edges[i]=e;
        nxt[e[0]].push_back(e[1]);
        nxtR[e[1]].push_back(e[0]);
    }

    bellman();

    //check for cycles
    affected.resize(n+1,false);    
    for(auto e:edges){
        if(dist[e[1]]<dist[e[0]]+e[2]){
            dist[e[1]]=dist[e[0]]+e[2];
            affected[e[1]]=true;
        }
    }


    vector<bool> beg(n+1,false), fin(n+1,false);
    function<void(int, vector<bool>&)> dfs = [&](int x, vector<bool>& reachable) {
        reachable[x]=true;
        for (int y : nxt[x]) {
            if (!reachable[y]) dfs(y, reachable);
        }
    };

    function<void(int, vector<bool>&)> dfsR = [&](int x, vector<bool>& reachable) {
        reachable[x]=true;
        for (int y : nxtR[x]) {
            if (!reachable[y]) dfsR(y, reachable);
        }
    };

    dfs(1, beg);
    dfsR(n, fin);
    F(x,1,n+1) {
        if (affected[x] && beg[x] && fin[x]) {
            cout<<"-1\n";
            return 0;
        }
    }

    cout<<dist[n]<<'\n';
}