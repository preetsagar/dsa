#include <bits/stdc++.h>
using namespace std;

// Method 1 DAG to think in the direction of DP

int n,m;
vector<vector<int>> graph;
long long dp[100100];
int mod=1e9+7;

int solve(int u){
    if(u==n) return 1;

    if(dp[u]!=-1) return dp[u];
    int ans=0;
    for(int v : graph[u]){
        ans=(ans%mod+solve(v)%mod)%mod;
    }

    return dp[u]=ans%mod;
}

int main(){
    cin>>n>>m;
    graph.resize(n+1,vector<int>());
    memset(dp,-1,sizeof(dp));

    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
    }

    cout<<solve(1);
    return 0;
}

// Method 2 using topological sort

const int MOD=1e9+7;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1,vector<int>());
    vector<int> indeg(n+1,0),path(n+1,0);

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indeg[b]++;
    }

    // kahn's algo - finding topo ordering
    queue<int> q;
    vector<int> topo;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0) q.push(-i);
    }
    while(!q.empty()){
        int u=-q.front(); q.pop();
        topo.push_back(u);

        for(int v : graph[u]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(-v);
            }
        }
    }

    // no of distinct path form 1..n
    path[1]=1;    // path[i] => no of ditinct path to reach node i
    for(int i=0; i<n; i++){
        int u=topo[i];
        for(int v : graph[u]){
            path[v]=(path[u]%MOD+path[v]%MOD)%MOD;
        }
    }
    cout<<path[n];

    return 0;
}