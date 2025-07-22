#include <bits/stdc++.h>
using namespace std;

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

int main() {
    int n,q;
    cin>>n>>q;
    DSU dsu = DSU(n);
    while(q--){
        int type, a, b; cin>>type>>a>>b;
        if(type==0){
            dsu.merge(a, b);
        }else{
            if(dsu.find(a)==dsu.find(b)) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
    }
    return 0;
}