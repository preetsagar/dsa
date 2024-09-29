#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t; cin>>t; while(t--){
        int n,k; cin>>n>>k;
        priority_queue<int> pq;

        while(n--){
            int t; cin>>t;
            pq.push(t);
        }
        int candy=0;
        while(k--&&!pq.empty()){
            int t=pq.top(); pq.pop();
            candy+=t;
            pq.push(t/2);
        }
        cout<<candy<<"\n";
    }
    return 0;
}