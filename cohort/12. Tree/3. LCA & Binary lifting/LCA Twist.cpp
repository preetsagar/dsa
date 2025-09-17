#include <bits/stdc++.h>
using namespace std;

int t,n,q;
vector<vector<int>> g, par;
vector<int> dep;

void dfs(int node, int depth, int parent){  
    par[node][0] = parent;
    dep[node] = depth;

    for(int i=1; i<20; i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }
    for(int v:g[node]){
        if(v!=parent){
            dfs(v, depth+1, node);
        }
    }
}

int lca(int u, int v){
    if(dep[v] > dep[u]) swap(u,v);

    // jumping at the same height
    for(int i=19; i>=0; i--){
        if((dep[u]-dep[v])&(1<<i)){
            u = par[u][i];
        }
    }

    if(u==v) return v;

    for(int i=19; i>=0; i--){
        if(par[u][i]!=par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[v][0];
}


int main() {
    cin>>t; while(t--){
        cin>>n;
        g.assign(n+1, vector<int>());
        par.assign(n+1, vector<int>(21, 0));
        dep.assign(n+1, 0);

        for(int i=1; i<n; i++){
            int a,b; cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1, 0, 0);

        cin>>q;
        while(q--){
            int a,b,c;
            cin>>a>>b>>c;

            int x = lca(a, b);
            int u = lca(a, c);
            int v = lca(b, c);

            if(lca(c, a)==lca(a, b)){
                cout<<lca(c, b)<<'\n';
            }
            else if(lca(c, b)==lca(a, b)){
                cout<<lca(c, a)<<'\n';
            }
            else{
                cout<<lca(a, b)<<'\n';
            }
        }
    }
    return 0;
}