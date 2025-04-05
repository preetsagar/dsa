#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<int> distanceArr;
vector<int> parent;

int ans=1e9;

void bfs(int s, int par){
    queue<int> q;
    q.push(s);
    distanceArr[s] = 0;
    parent[s] = -1;

    while(!q.empty()){
        int u =  q.front(); q.pop();
        for(int v:graph[u]){
            if(v==parent[u]) continue;
            if(distanceArr[v]==1e9){
                q.push(v);
                parent[v] = u;
                distanceArr[v] = 1 + distanceArr[u];
            }
            else if(distanceArr[v] <= distanceArr[u]){
                ans = min(ans, distanceArr[u]+distanceArr[v]+1);
            }
        }
    }
}

int main() {
    cin>>n>>m;
    graph.resize(n+1, vector<int>());

    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        distanceArr.assign(n+1, 1e9);
        parent.assign(n+1, 1e9);
        bfs(i, -1);
    }

    cout<< ((ans==1e9) ? -1 : ans);

    return 0;
}