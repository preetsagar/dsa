#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MP make_pair

int n,m, mod=1e9+7;
vector<vector<pair<int, int>>> graph;
vector<int> vis, path, dis, maxF, minF;

void dijkstra(int u){
    priority_queue<pair<int, int>> pq;

    pq.push(MP(0, u));
    dis[u] = 0;
    path[u] = 1;
    maxF[u] = 0;
    minF[u] = 0;

    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        int u = t.second;

        if(vis[u]) continue;
        vis[u] = 1;

        for(auto neg : graph[u]){
            int v=neg.first, weg = neg.second;
            if(dis[v] > dis[u]+weg){
                dis[v] = dis[u]+weg;
                pq.push({-dis[v], v});
                path[v] = path[u];
                minF[v] = minF[u]+1;
                maxF[v] = maxF[u]+1;
            }
            else if(dis[v] == dis[u]+weg){
                path[v] = (path[v] + path[u])%mod;
                minF[v] = min(minF[v], minF[u]+1);
                maxF[v] = max(maxF[v], maxF[u]+1);
            }
        }
    }
}

signed main() {
    cin>>n>>m;
    graph.resize(n+1);
    vis.assign(n+1, 0);
    path.assign(n+1, 0);
    maxF.assign(n+1, 0);
    minF.assign(n+1, 1e18);
    dis.assign(n+1, 1e18);
    for(int i=0; i<m; i++){
        int u,v,w; cin>>u>>v>>w;
        graph[u].push_back({v, w});
    }
    dijkstra(1);
    if(dis[n]==1e18) cout<<-1;
    else{
        cout<<dis[n]<<" "<<((path[n])%mod)<<" "<<minF[n]<<" "<<maxF[n];
    }
    return 0;
}