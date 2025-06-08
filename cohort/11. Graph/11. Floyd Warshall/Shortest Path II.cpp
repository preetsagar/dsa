#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m,q;
vector<vector<int>> adj;

signed main() {
    cin>>n>>m>>q;
    adj.resize(n+1, vector<int>(n+1, 1e18));
    for(int j=0; j<m; j++){
        int u,v,w; cin>>u>>v>>w;
        adj[u-1][v-1] = min(adj[u-1][v-1], w);
        adj[v-1][u-1] = min(adj[v-1][u-1], w);
    }
    for(int i = 0; i < n; i++) adj[i][i] = 0;   // Distance from a node to itself is 0 [ye bhul gya tha]

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }

    while(q--){
        int u,v; cin>>u>>v;
        cout<<(adj[u-1][v-1]==1e18 ? -1 : adj[u-1][v-1])<<"\n";
    }
    return 0;
}