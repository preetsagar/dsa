#include <bits/stdc++.h>
using namespace std;

int n,m,q,color;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int u,int col){
    visited[u]=col;
    for(int v : graph[u]){
        if(!visited[v]){
            dfs(v,col);
        }
    }
}

int main(){
    cin>>n>>m>>q;
    graph.resize(n+1);
    visited.resize(n+1,0);

    while(m--){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            color++;
            dfs(i,color);
        }
    }

    map<int,int> sizeOfComponent;
    for(int i=1; i<=n; i++){
        sizeOfComponent[visited[i]]++;
    }

    while(q--){
        int ch,a,b; cin>>ch;
        if(ch==1){
            cin>>a;
            cout<<sizeOfComponent[visited[a]]<<"\n";
        }
        else{
            cin>>a>>b;
            if(visited[a]==visited[b]) cout<<"YES\n";
            else cout<<"NO\n";
        }

    }
    return 0;
}