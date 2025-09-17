#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> graph;
int mod=1e9+7;
long dis[200010];

void dfs(int u, int par){
    dis[u] = dis[par]+1;
    for(int v:graph[u]){
        if(v!=par){
            dfs(v, u);
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
    }
    dis[0]=0;
    dfs(1, 0);
    int oneEnd, d=0;
    for(int i=1; i<=n; i++){
        if(dis[i] > d){
            d = dis[i];
            oneEnd = i;
        }
    }
    dfs(oneEnd, 0);
    d=0;
    for(int i=1; i<=n; i++){
        if(dis[i] > d){
            d = dis[i];
            oneEnd = i;
        }
    }
    cout<<(d-1)%mod;
    return 0;
}