#include <bits/stdc++.h>
using namespace std;

using ll=long long;

ll dis[505][505];
int n,m,q;

void floydWarshall(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}

int main() {
    cin>>n>>m>>q;

    // initially inf for dis array
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j) dis[i][j]=1e18;
            else dis[i][j]=0;
        }
    }

    // input of adjacency matrix
    for(int i=0; i<m; i++){
        ll a,b,wt;
        cin>>a>>b>>wt;
        dis[a][b]=min(wt,dis[a][b]);
        dis[b][a]=min(wt,dis[b][a]);
    }

    floydWarshall();

    // query
    for(int i=0; i<q; i++){
        int u,v;
        cin>>u>>v;
        if(dis[u][v]==1e18) cout<<"-1\n";
        else cout<<dis[u][v]<<endl;
    }
    return 0;
}