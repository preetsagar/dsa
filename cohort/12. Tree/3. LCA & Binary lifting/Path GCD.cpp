#include <bits/stdc++.h>
using namespace std;

int t,n,q;
vector<int> val, dep;
vector<vector<int>> g, par, dp;

int gcdd(int a, int b){
    if(b>a) return gcdd(b, a);
    if(b==0) return a;
    return gcdd(b, a%b);
}

void dfs(int node, int parent, int depth){
    dep[node] = depth;
    par[node][0] = parent;
    dp[node][0] = val[node];

    for(int i=1; i<20; i++){
        par[node][i] = par[par[node][i-1]][i-1];
        dp[node][i] = gcdd(dp[node][i-1], dp[par[node][i-1]][i-1]);
    }

    for(int v:g[node]){
        if(v!=parent){
            dfs(v, node, depth+1);
        }
    }
}

int pathGcd(int u, int v){
    if(dep[v] > dep[u]) swap(u, v);

    int ans=0;
    for(int i=19; i>=0; i--){
        if((dep[u]-dep[v])&(1<<i)){
            ans = gcdd(ans, dp[u][i]);
            u = par[u][i];
        }
    }
    if(u==v) return gcdd(ans, val[u]);

    for(int i=19; i>=0; i--){
        if(par[u][i]!=par[v][i]){
            ans = gcdd(ans, dp[u][i]);
            u = par[u][i];
            ans = gcdd(ans, dp[v][i]);
            v = par[v][i];
        }
    }

    ans = gcdd(ans, val[u]);
    ans = gcdd(ans, val[v]);
    ans = gcdd(ans, val[par[u][0]]);
    return ans;
}

int main() {
    cin>>t;
    while(t--){
        cin>>n;
        val.assign(n+1, 0);
        dep.assign(n+1, 0);
        g.assign(n+1, vector<int>());
        par.assign(n+1, vector<int>(20, 0));
        dp.assign(n+1, vector<int>(20, 0));

        for(int i=1; i<=n; i++) cin>>val[i];
        for(int i=1; i<n; i++){
            int a,b; cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        dfs(1, 0, 0);
        cin>>q;
        while(q--){
            int u, v;
            cin>>u>>v;
            cout<<pathGcd(u, v)<<'\n';
        }
    }
    return 0;
}