#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define int long long

struct DSU{
    int n, size;
    vector<int> parent, rank;
    DSU(int a){
        n = a;
        size = n;
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
        rank.resize(n+1, 1);
    }

    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y){
        int xrep = find(x), yrep = find(y);
        if(xrep==yrep) return;

        size--;
        if(rank[xrep] > rank[yrep]){
            parent[yrep] = xrep;
            rank[xrep] += rank[yrep];
        }
        else{
            parent[xrep] = yrep;
            rank[yrep] += rank[xrep];
        }
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin>>n>>m;
    DSU dsu(n);
    vector<pair<int, pair<int, int>>> edges;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        edges.push_back(MP(w, MP(u, v)));
    }
    sort(edges.begin(), edges.end());
    
    int ans=0;
    for(auto j:edges){
        int w = j.first;
        int u = j.second.first;
        int v = j.second.second;

        if(dsu.find(u)!=dsu.find(v)){
            ans += w;
            dsu.merge(u, v);
        }
    }

    if(dsu.size==1) cout<<ans;
    else cout<<"IMPOSSIBLE";
    return 0;
}