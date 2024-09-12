#include <bits/stdc++.h>
#include "./DSUClass.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> query;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        query.push_back({c,{a,b}});
    }
    sort(query.begin(),query.end());

    UnionFind uf(n);
    long long ans=0;
    for(auto i:query){
        int a=i.second.first;
        int b=i.second.second;
        int c=i.first;

        int arep=uf.find(a);
        int brep=uf.find(b);
        if(arep!=brep){
            uf.merge(a,b);
            ans+=c;
        }
    }
    // cout<<uf.size()<<" "<<ans<<endl;
    if(uf.size()==1){
        cout<<ans;
    }
    else cout<<"IMPOSSIBLE";

    return 0;
}