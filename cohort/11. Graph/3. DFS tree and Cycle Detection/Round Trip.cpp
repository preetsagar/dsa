#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<int> color,parent;
int isCycle=0;

void detectCycleInUndirectedGraph(int u,int par){
    color[u]=2;
    parent[u]=par;
    for(int v : graph[u]){
        if(v==parent[u]) continue;
        if(color[v]==1){
            detectCycleInUndirectedGraph(v,u);
        }
        else if(color[v]==2){
            isCycle=1;
        }
    }
    color[u]=3;
}

int main(){
    cin>>n>>m;
    graph.resize(n+1,vector<int>());
    color.resize(n+1,1);
    parent.resize(n+1,1);
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int u=1; u<=n; u++){
        if(color[u]==1){
            detectCycleInUndirectedGraph(u,-1);
        }
    }
    if(isCycle) cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}