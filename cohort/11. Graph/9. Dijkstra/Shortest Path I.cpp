#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<pair<int, int>>> graph;
vector<long long> dis, vis;

void dijkstra(int st){
    dis[st] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push({-0, st});

    while(!pq.empty()){
        auto top = pq.top(); pq.pop();
        int u = top.second, w=-top.first;

        if(vis[u]==1) continue;
        vis[u] = 1;

        for(auto v:graph[u]){
            if(dis[v.first] > dis[u]+v.second){
                dis[v.first] = dis[u]+v.second;
                pq.push({-dis[v.first], v.first});
            }
        }
    }
}

int main() {
    cin>>n>>m;
    graph.resize(n+1);
    dis.resize(n+1, 1e18);
    vis.resize(n+1, 0);
    for(int i=0; i<m; i++){
        int u,v,w; cin>>u>>v>>w;
        graph[u].push_back({v, w});
    }
    dijkstra(1);
    for(int i=1; i<=n; i++) cout<<dis[i]<<" ";
    return 0;
}