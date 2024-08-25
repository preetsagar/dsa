#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int> col,parent;
int ans = 0;

void DFS(int u,int par){
    col[u] = 2;
    parent[u] = par;
    for(int v : adj[u]){
        if(v == par) continue;  // NOTE

        if(col[v] == 1) DFS(v,u);
        else if(col[v] == 2){
            ans = 1;
        }
    }
    col[u] = 3;
}


int main() {
    cin >> n >> m;
    adj.assign(n + 1,vector<int>());
    col.assign(n + 1,1);
    parent.assign(n + 1,0);

    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(col[i] == 1 && !ans){
            DFS(i,0);
        }
    }

    cout << (ans ? "YES" : "NO");
    return 0;
}