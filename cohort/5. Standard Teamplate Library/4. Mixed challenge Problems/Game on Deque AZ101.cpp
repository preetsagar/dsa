#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin>>t; while(t--){
        int n,q; cin>>n>>q;
        deque<int> dq;
        int mx=0,idx;
        for(int i=0; i<n; i++){
            int x; cin>>x; dq.push_back(x);
            if(x>mx){
                mx=x; idx=i;
            }
        }
        map<int,pair<int,int>> _map;
        // cout<<idx<<"\n";
        for(int i=0; i<=idx; i++){
            int a=dq.front(); dq.pop_front();
            int b=dq.front(); dq.pop_front();
            _map[i+1]={a,b};
            // cout<<i+1<<" -> "<<a<<" "<<b<<"\n";
            if(a>b){
                dq.push_front(a);
                dq.push_back(b);
            }
            else{
                dq.push_front(b);
                dq.push_back(a);
            }
        }
        while(q--){
            int x; cin>>x;
            if(_map.find(x)!=_map.end()){
                cout<<_map[x].first<<" "<<_map[x].second<<"\n";
            }
            else{
                int a=dq.front();
                // for(int i:dq) cout<<i<<" "; cout<<"\n";

                x-=(idx+2);
                x%=(n-1);
                // cout<<"x = "<<x<<"\n";
                int b=dq[1+x];
                cout<<a<<" "<<b<<"\n";
            }
        }
    }
    return 0;
}