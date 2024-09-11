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

    void merge(int x,int y){
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