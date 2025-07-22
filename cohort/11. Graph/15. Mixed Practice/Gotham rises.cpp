// Method 1 ---------------------------------
#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU {
    int n, size;
    vector<int> parent, rank;
    DSU(int a) {
        n = a;
        size = n;
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
        rank.resize(n + 1, 1);
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        int xrep = find(x), yrep = find(y);
        if (xrep == yrep) return;
        size--;
        if (rank[xrep] > rank[yrep]) {
            parent[yrep] = xrep;
            rank[xrep] += rank[yrep];
        } else {
            parent[xrep] = yrep;
            rank[yrep] += rank[xrep];
        }
    }
};

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, m, c, r;
        cin >> n >> m >> c >> r;
        DSU dsu(n);
        int cost = 0;
        while (m--) {
            int u, v; cin >> u >> v;
            if (dsu.find(u) != dsu.find(v)) {
                dsu.merge(u, v);
                cost += r;
            }
        }
        cost = min(n * c, dsu.size * c + cost);
        cout << cost << "\n";
    }
    return 0;
}

// Method 2 ---------------------------------
#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> color;
vector<vector<int>> graph;

void dfs(int u, int col){
    color[u] = col;
    for(int v:graph[u]){
        if(color[v]==0){
            dfs(v, col);
        }
    }
}

signed main() {
    int t; cin>>t; while(t--){
        int n,m,c,r; cin>>n>>m>>c>>r;
        color.assign(n+1, 0);
        graph.assign(n+1, vector<int>());
        for(int i=0; i<m; i++){
            int u,v; cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int col=1;
        for(int i=1; i<=n; i++){
            if(!color[i]){
                dfs(i, col);
                col++;
            }
        }
        map<int, int> mp;
        for(int i=1; i<=n; i++){
            // cout<<color[i]<<" ";
            mp[color[i]]++;
        }
        int ans=0;
        for(auto i:mp){
            ans += (i.second-1)*r;
            ans += c;
        }
        ans = min(ans, n*c);
        cout<<ans<<"\n";
    }

    return 0;
}