#include <bits/stdc++.h>
using namespace std;

#define int long

int t, n;
vector<pair<int, pair<int, int>>> edges;
vector<vector<int>> g;

struct DSU{
    int n;
    vector<int> rank, par;

    DSU(int a){
        n = a;
        rank.resize(n+1, 1);
        par.resize(n+1);
        for(int i=1; i<=n;i++) par[i] = i;
    }

    int find(int x){
        if(x != par[x]){
            return par[x] = find(par[x]);
        }
        return x;
    }

    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x!=y){
            if(rank[x]< rank[y]) swap(x, y);
            par[y] = x;
            rank[x] += rank[y];
        }
    }

    int getRank(int x) {return rank[x];}
};

signed main() {
    cin>>t; while(t--){
        cin>>n;
        edges.clear();
        g.assign(n+1, vector<int>());
        DSU dsu = DSU(n);
        for(int i=1; i<n; i++){
            int a, b, d; cin>>a>>b>>d;
            g[a].push_back(b);
            g[b].push_back(a);
            edges.push_back({d, {a, b}});
        }

        sort(edges.begin(), edges.end());
        reverse(edges.begin(), edges.end());

        int ans=0;

        for(auto e:edges){
            int d = e.first;
            int u = e.second.first;
            int v = e.second.second;

            int x = dsu.find(u);
            int y = dsu.find(v);
            int xx = dsu.getRank(x);
            int yy = dsu.getRank(y);

            ans += xx * d * yy;
            dsu.merge(x, y);
        }
        cout<<ans<<'\n';
    }
    return 0;
}