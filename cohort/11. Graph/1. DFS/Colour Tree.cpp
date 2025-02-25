#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> adj[n+1];
    int ans=0;
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        u=adj[u].size();
        v=adj[v].size();
        ans=max({ans,u,v});
    }
    cout<<ans+1;
    return 0;
}