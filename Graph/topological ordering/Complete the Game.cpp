#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1,vector<int>());
    vector<int> indeg(n + 1,0),dp(n + 1,0);

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        indeg[b]++;
    }

    // kahn's algo - finding topo ordering
    queue<int> q;
    vector<int> topo;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0) q.push(-i);
    }
    while(!q.empty()){
        int u = -q.front(); q.pop();
        topo.push_back(u);

        for(int v : graph[u]){
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(-v);
            }
        }
    }

    // finding path
    dp[1] = 1;    // dp[i] => no of ditinct path to reach node i
    for(int i = 0; i < n; i++){
        int u = topo[i];
        for(int v : graph[u]){
            dp[v] = (dp[u] % MOD + dp[v] % MOD) % MOD;
        }
    }
    cout << dp[n];

    return 0;
}