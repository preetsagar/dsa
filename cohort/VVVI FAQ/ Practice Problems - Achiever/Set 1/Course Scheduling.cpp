#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<int> indegree;

int main() {
    cin>>n>>m;
    graph.resize(n+1);
    indegree.resize(n+1, 0);

    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        indegree[v]++;
    }

    vector<int> topo;
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u=q.front();q.pop();
        topo.push_back(u);

        for(int v:graph[u]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }

    // for(int i:topo) cout<<i<<" "; cout<<"\n";

    if(topo.size()==n) cout<<"Yes";
    else cout<<"No";
    return 0;
}