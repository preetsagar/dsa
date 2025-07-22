#include <bits/stdc++.h>
using namespace std;

class UnionFind{
    int n,st_size;
    vector<int> parent,rank;

    public:
        UnionFind(){}
        UnionFind(int a){
            n=st_size=a;
            rank.assign(n+1,1);
            parent.assign(n+1,0);
            for(int i=1; i<=n; i++) parent[i]=i;
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
            for(int i=1; i<=n; i++) { parent[i]=i; rank[i]=1; }
        }
};

int main() {
    int n,m,q;
    cin>>n>>m>>q;
    UnionFind uf(n);
    map<int, pair<int, int>> edges;
    vector<pair<int, int>> query;
    set<int> st;
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        edges[i+1] = {a, b};
        st.insert(i+1);
    }
    for(int i=0; i<q; i++){
        int a,b;
        cin>>a;
        if(a==2){
            query.push_back({2, 2});
        }
        else{
            cin>>b;
            query.push_back({a, b});
            st.erase(b);
        }
    }

    for(int i:st){
        uf.merge(edges[i].first, edges[i].second);
    }
    reverse(query.begin(), query.end());

    vector<int> ans;
    for(auto i:query){
        int a = i.first;
        int b = i.second;
        if(a==2){
            ans.push_back(uf.size());
        }
        else{
            uf.merge(edges[b].first, edges[b].second);
        }
    }

    reverse(ans.begin(), ans.end());
    for(int i:ans){
        cout<<i<<"\n";
    }
    
    return 0;
}