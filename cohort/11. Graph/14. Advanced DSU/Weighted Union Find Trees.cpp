#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int n,q;

struct DSU{
    int n, size;
    vector<pii> parent;
    vector<int> rank;

    DSU(int a){
        size = n = a;
        parent.resize(n+1);
        for(int i=0;i<=n; i++){
            parent[i] = {i, 0};
        }
        rank.resize(n+1, 1);
    }

    pii find(int x){
        if(x == parent[x].first) return parent[x];
        
        pii xx = find(parent[x].first);
        xx.second += parent[x].second;
        parent[x] = xx;
        return parent[x];
    }

    void merge(int u, int v, int x){
    pii uu = find(u);
    pii vv = find(v);

    int urep = uu.first;
    int vrep = vv.first;

    if(urep == vrep) return;

    if(rank[urep] > rank[vrep]){
        parent[vrep] = {urep, uu.second - vv.second - x};
        rank[urep] += rank[vrep];
    }else{
        parent[urep] = {vrep, vv.second - uu.second + x};
        rank[vrep] += rank[urep];
    }
}

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>q;
    DSU dsu(n);
    while(q--){
        int type; cin>>type;
        if(type==0){
            int u,v,w; cin>>v>>u>>w;
            dsu.merge(u, v, w);
        }
        else{
            int u,v; cin>>u>>v;
            pii uu = dsu.find(u);
            pii vv = dsu.find(v);
             if(uu.first != vv.first) cout<<'?'<<'\n';
            else cout<<(vv.second - uu.second)<<'\n';
        }
    }
    return 0;
}