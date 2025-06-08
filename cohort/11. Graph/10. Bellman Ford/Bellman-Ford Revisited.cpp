#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
vector<pair<int, pair<int, int>>> edges;
vector<int> dis;

signed main() {
    cin>>n>>m;
    dis.resize(n+1, 1e18);
    for(int i=0; i<m; i++){
        int u,v,w; cin>>u>>v>>w;
        edges.push_back({u, {v, -w}});
    }
    dis[1]=0;
    for(int i=1; i<=n; i++){
        for(auto j:edges){
            int u=j.first, v=j.second.first, w=j.second.second;
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
            }
        }
    }

    for(auto j:edges){
        int u=j.first, v=j.second.first, w=j.second.second;
        if(dis[u]!=1e8 && dis[v]!=1e18 && dis[v] > dis[u]+w){   // Check for negative cycles and if reachable(1e18 is unreachable)
            cout<<-1;
            return 0;
        }
    }

    cout<<-dis[n];

    return 0;
}