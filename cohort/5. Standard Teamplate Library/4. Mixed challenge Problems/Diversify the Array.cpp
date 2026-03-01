#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin>>t; while(t--){
        int n,k; cin>>n>>k;
        map<int,int> _map;
        for(int i=0; i<n; i++){
            int a; cin>>a;
            _map[a]++;
        }
        int ans=(n*(n-1))/2;
        priority_queue<int> pq;
        for(auto i:_map){
            pq.push(i.second);
        }
        for(int i=0; i<k; i++){
            if(!pq.empty()&&pq.top()>1){
                int a=pq.top();pq.pop();
                pq.push(--a);
            }
            else break;
        }
        while(!pq.empty()){
            int a=pq.top();pq.pop();
            ans-=(a*(a-1))/2;
        }
        cout<<ans<<"\n";
    }
    return 0;
}