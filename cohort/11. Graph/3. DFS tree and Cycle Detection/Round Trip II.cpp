#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int> col;
int ans=0;

void detectCycleInDirectedGraph(int u){
    col[u]=2;
    for(int v : adj[u]){
        if(col[v]==1) detectCycleInDirectedGraph(v);
        else if(col[v]==2){
            ans=1;
        }
    }
    col[u]=3;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>m;
        adj.assign(n+1,vector<int>());
        col.assign(n+1,1);

        for(int i=0; i<m; i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
        }

        for(int i=1; i<=n; i++){
            if(col[i]==1&&!ans){
                detectCycleInDirectedGraph(i);
            }
        }

        cout<<(ans ? "Yes" : "No")<<endl;
    }
    return 0;
}