#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int> col;
int ans=1;

void bipartedGraph(int u,int color){
    col[u]=color;
    for(int v : adj[u]){
        if(col[v]==0){
            bipartedGraph(v,color^3);
        }
        else if(col[v]==color){
            ans=0;
        }
    }
}

int main(){
    cin>>n>>m;
    adj.assign(n+1,vector<int>());
    col.assign(n+1,0);

    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        if(col[i]==0&&ans){
            bipartedGraph(i,1);
        }
    }

    cout<<(ans ? "YES" : "NO");
    return 0;
}