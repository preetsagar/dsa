#include <bits/stdc++.h>
using namespace std;

int t, n, q;
vector<vector<int>> g, par;
vector<int> dep, partialSum;

void dfs(int node, int parent, int depth){
    dep[node] = depth+1;
    par[node][0] = parent;

    for(int i=1; i<=19; i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }

    for(int v:g[node]){
        if(v!=parent){
            dfs(v, node, depth+1);
        }
    }
}

int lca(int u, int v){
    if(dep[v] > dep[u]) swap(u, v);

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
    return par[u][0];
}

void add(int u, int v, int x){
    partialSum[u] += x;
    partialSum[v] += x;
    partialSum[lca(u, v)] -= x;
    partialSum[par[lca(u, v)][0]] -= x;
}

void pushAll(int node, int parent){
    for(int v:g[node]){
        if(v!=parent){
            pushAll(v, node);
        }
    }
    partialSum[par[node][0]] += partialSum[node];
}


int main() {
    cin>>t;
    while(t--){
        cin>>n;
        dep.assign(n+1, 0);
        partialSum.assign(n+1, 0);
        g.assign(n+1, vector<int>());
        par.assign(n+1, vector<int>(20, 0));

        for(int i=1; i<n; i++){
            int u,v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1, 0, 0);

        cin>>q;
        while(q--){
            int u, v, x;
            cin>>u>>v>>x;
            add(u, v, x);
        }
        pushAll(1, 0);
        for(int i=1; i<=n; i++){
            cout<<partialSum[i]<<" ";
        }
        cout<<'\n';

    }
    return 0;
}