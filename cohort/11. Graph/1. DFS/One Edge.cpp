#include <bits/stdc++.h>
using namespace std;

#define int long long

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

signed main(){
    cin>>n>>m;
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

    vector<int> arr;
    for(auto i:sizeOfComponent){
        arr.push_back(i.second);
    }

    long long ans=0;
    int sum=0;
    for(int i : arr) sum+=i;

    sum-=arr[0];
    for(int i=1; i<arr.size(); i++){
        ans+=(arr[i-1]*sum);
        sum-=arr[i];
    }

    cout<<ans<<"\n";

    return 0;
}