#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
int n,m;
using state = pair<ll,ll>;
vector<vector<state>> graph;
vector<ll> dis;
vector<int> vis;
vector<pair<int,state>> edges;

void dijkastra(int src){
    priority_queue<state> pq;
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
    graph.assign(n + 1,vector<state>());
    dis.assign(n + 1,1e18);
    vis.assign(n + 1,0);
    for(int i = 0; i < m; i++){
        int a,b,dist;
        cin >> a >> b >> dist;
        graph[a].push_back({b,dist});
        graph[b].push_back({a,dist});
        edges.push_back({a,{b,dist}});
    }
    int src;
    cin >> src;
    dijkastra(src);

    ll ans = -1e18;
    for(auto t : edges){
        ll a = dis[t.F];
        ll b = dis[t.S.F];
        ll dist = t.S.S;

        if(abs(a - b) == dist){
            ans = max(ans,max(a,b) * 10);
        }
        else{
            ans = max(ans,(a + b + dist) * 5);
        }
    }

    cout << ans;

    return 0;
}