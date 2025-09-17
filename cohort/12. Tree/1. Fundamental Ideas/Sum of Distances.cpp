#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> graph;
vector<pair<int, int>> edges;
int mod=1e9+7;
long nodes[200010];

void dfs(int u, int par){
    nodes[u] = 1;
    for(int v:graph[u]){
        if(v!=par){
            dfs(v, u);
            nodes[u] += nodes[v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    graph.resize(n+1);
    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges.push_back({u, v});
    }
    dfs(1, 0);
    long ans=0;
    for(auto i:edges){
        long t = min(nodes[i.first], nodes[i.second]);
        ans +=  t * (n-t);
    }
    cout<<ans;

    return 0;
}