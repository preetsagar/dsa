#include <bits/stdc++.h>
using namespace std;

int t, n,m;

class DSU {
    vector<int> rank, parent;

    public:

    DSU(int n){
        rank.resize(n+1);
        for(int i=0; i<=n; i++) rank[i] = 1;

        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y){
        int xp = find(x);
        int yp = find(y);

        if(xp!=yp){
            if(rank[xp] < rank[yp]) swap(xp, yp);
            rank[xp] += rank[yp];
            parent[yp] = xp;
        }
    }
};

int main() {
    cin>>t; while(t--){
        cin>>n>>m;
        DSU dsu(n);
        for(int i=0; i<m; i++){
            int x,y;
            cin>>x>>y;
            dsu.merge(x, y);
        }
        vector<int> source(n), target(n);

        for(int i=0; i<n; i++){
            cin>>source[i];
        }
        for(int i=0; i<n; i++){
            cin>>target[i];
        }

        vector<int> pos(n + 1);
        for (int i = 0; i<n; i++){
            pos[source[i]] = i+1;
        }

        int ans=1;
        for(int i=0; i<n; i++){
            if(source[i]!=target[i] && dsu.find(i+1)!=dsu.find(pos[target[i]])){
                ans=0; break;
            }
        }
        if(ans) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}