#include <bits/stdc++.h>
using namespace std;

vector<int> vis;
vector<vector<int>> graph;

void BFS(int node){
    queue<int> q;
    q.push(node);
    vis[node]=1;

    while(!q.empty()){
        int u=q.front(); q.pop();

        for(int v : graph[u]){
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+1,vector<int>());

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vis.resize(n+1,0);
    int count=0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            count++;
            BFS(i);
        }
    }
    cout<<count-1;
    return 0;
}