#include <bits/stdc++.h>
using namespace std;

class UnionFind{
    int n,st_size;
    vector<int> parent,rank;

public:
    UnionFind(){}
    UnionFind(int a){
        n=st_size=a;
        rank.assign(n,1);
        parent.assign(n,0);
        for(int i=0; i<n; i++) parent[i]=i;
    }

    int find(int x){
        if(x!=parent[x]) return parent[x]=find(parent[x]);
        return x;
    }

    void marge(int x,int y){
        int xrep=find(x);
        int yrep=find(y);
        if(xrep!=yrep){
            if(rank[xrep]>=rank[yrep]){
                rank[xrep]+=rank[yrep];
                parent[yrep]=xrep;
            }
            else{
                rank[yrep]+=rank[xrep];
                parent[xrep]=yrep;
            }
            st_size--;
        }
    }

    int size(){ return st_size; }
    void reset(){
        for(int i=0; i<n; i++) { parent[i]=i; rank[i]=1; }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,q;
    cin>>n>>q;
    UnionFind uf(n);
    for(int i=0; i<q; i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0){
            uf.marge(b,c);
        }
        else{
            int arep=uf.find(b);
            int brep=uf.find(c);
            cout<<(arep==brep?1:0)<<"\n";
        }
    }

    return 0;
}