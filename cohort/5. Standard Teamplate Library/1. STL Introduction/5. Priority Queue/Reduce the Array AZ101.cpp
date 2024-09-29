#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        priority_queue<int> pq;

        while(n--){
            int t; cin>>t;
            pq.push(-t);
        }
        int cost=0;
        while(pq.size()>1){
            int t1=pq.top(); pq.pop();
            int t2=pq.top(); pq.pop();
            cost+=(-t1+-t2);
            pq.push(t1+t2);
        }
        cout<<cost<<"\n";
    }
    return 0;
}