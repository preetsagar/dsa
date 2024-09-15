#include <bits/stdc++.h>
using namespace std;

class Unionfind{
    int n;
    vector<pair<int,int>> parent;
    vector<int> rank;
public:
    Unionfind(){}
    Unionfind(int x){
        n=x;
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i]={i,0};
            rank[i]=1;
        }
    }

    pair<int,int> find(int x){
        if(x!=parent[x].first){
            auto t=find(parent[x].first);
            return parent[x]={t.first,parent[x].second+t.second};
        }
        return parent[x];
    }

    void merge(int a,int b,int z) {
        auto arep=find(a);
        auto brep=find(b);

        if(arep.first!=brep.first) {
            if(rank[arep.first]>=rank[brep.first]) {
                parent[brep.first]={arep.first,arep.second-brep.second-z};
                rank[arep.first]+=rank[brep.first];
            }
            else {
                parent[arep.first]={brep.first,brep.second-arep.second+z};
                rank[brep.first]+=rank[arep.first];
            }
        }
    }

    void print(){
        for(auto i:parent){
            cout<<"("<<i.first<<","<<i.second<<") ";
        }
        cout<<"\n";
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,q; cin>>n>>q;
    Unionfind uf(n);
    // uf.print();
    while(q--){
        int a,b,c,d;
        cin>>a;
        if(!a){
            cin>>b>>c>>d;
            uf.merge(b,c,d);
            // uf.print();
        }
        else{
            cin>>b>>c;
            auto brep=uf.find(b);
            auto crep=uf.find(c);
            if(brep.first!=crep.first) cout<<"?\n";
            else{
                cout<<(brep.second-crep.second)<<"\n";
            }
        }
    }

    return 0;
}