#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<vector<int>> graph;
vector<int> dis;

void bfs(int st){
    queue<int> q;
    q.push(st);
    dis[st] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(int i=1; i<=6; i++){
            int v = u+i;
            if(v>100) continue;
            if(!graph[v].empty()) v = graph[v][0];
            if(dis[v] > dis[u]+1){
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin>>t; while(t--){
        cin>>n;
        graph.assign(110, {});
        dis.assign(110, 1e9);
        for(int i=0; i<n; i++){
            int u,v; cin>>u>>v;
            graph[u].push_back(v);
        }
        cin>>m;
        for(int i=0; i<m; i++){
            int u,v; cin>>u>>v;
            graph[u].push_back(v);
        }
        bfs(1);

        cout<<(dis[100]==1e9 ? -1 : dis[100])<<"\n";
    }
    return 0;
}