#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1,vector<int>());
    vector<int> indeg(n + 1,0);

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        indeg[b]++;
    }

    // kahn's algo
    priority_queue<int> pq;
    vector<int> topo;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0) pq.push(-i);
    }
    while(!pq.empty()){
        int u = -pq.top(); pq.pop();
        topo.push_back(u);

        for(int v : graph[u]){
            indeg[v]--;
            if(indeg[v] == 0){
                pq.push(-v);
            }
        }
    }
    // print lexographically smallest topo sort
    if(topo.size() == n)
        for(int i : topo) cout << i << " ";
    else
        cout << "-1";

    return 0;
}