#include <bits/stdc++.h>
using namespace std;
#define int signed

signed main() {
    int t; cin>>t; while(t--){
        int n,m; cin>>n>>m;
        map<int,int> _map;
        while(n--){
            int x,u;
            cin>>x>>u;
            _map[x*u]++;
        }
        int count=0;
        while(m--){
            int y,v;
            cin>>y>>v;
            if(_map.find(y*v)!=_map.end()){
                _map[y*v]--;
                count++;
                if(_map[y*v]==0) _map.erase(y*v);
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}