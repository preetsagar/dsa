#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<int> outdeg;

int main() {
    cin>>n>>m;
    graph.resize(n+1);
    outdeg.resize(n+1,0);
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        graph[v].push_back(u);
        outdeg[u]++;
    }

    priority_queue<int> pq;
    for(int i=1; i<=n; i++){
        if(outdeg[i]==0) pq.push(i);
    }

    vector<int> topo, ans(n+1);
    int j=n;
    while(!pq.empty()){
        int u = pq.top(); pq.pop();
        ans[u] = j--;
        topo.push_back(u);
        for(int v:graph[u]){
            outdeg[v]--;
            if(outdeg[v]==0){
                pq.push(v);
            }
        }
    }
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";

    return 0;
}