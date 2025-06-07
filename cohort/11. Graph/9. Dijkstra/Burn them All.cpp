#include <bits/stdc++.h>
using namespace std;

int n,m,A;
vector<vector<pair<int, int>>> graph;
vector<pair<int, pair<int, int>>> edge;
vector<long long> dis, vis;

void dijkstra(int st){
    priority_queue<pair<long long, int>> pq;
    pq.push({-0, st});
    dis[st] = 0;

    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        int u = t.second;

        if(vis[u]==1) continue;
        vis[u]=1;

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
        graph[v].push_back({u, w});
        edge.push_back({u,{v, w}});
    }
    cin>>A;
    dijkstra(A);

    long long ans = 0;
    for(auto i:edge){
        long long d1=dis[i.first], d2=dis[i.second.first];
        long long w = i.second.second;
        if(abs(d1-d2) == w){
            ans = max(ans, max(d1, d2)*10);
        }
        else{
            ans = max(ans, (d1+d2+w)*5);
        }
    }
    cout<<ans;
    return 0;
}