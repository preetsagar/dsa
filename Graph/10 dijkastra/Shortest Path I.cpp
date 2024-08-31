#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
int n,m;
vector<vector<pair<int,ll>>> graph;
vector<ll> dis;
vector<int> vis;

void dijkastra(int src){
    priority_queue<pair<ll,int>> pq;
    dis[src] = 0;
    pq.push({0,src});

    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        int u = t.S;

        if(vis[u]) continue;
        vis[u] = 1;

        for(auto v : graph[u]){
            if(dis[v.F] > dis[u] + v.S){
                dis[v.F] = dis[u] + v.S;
                pq.push({-dis[v.F],v.F});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    graph.assign(n + 1,vector<pair<int,ll>>());
    dis.assign(n + 1,1e18);
    vis.assign(n + 1,0);
    for(int i = 0; i < m; i++){
        int a,b,dist;
        cin >> a >> b >> dist;
        graph[a].push_back({b,dist});
    }
    dijkastra(1);

    for(int i = 1; i <= n; i++) cout << dis[i] << " ";

    return 0;
}