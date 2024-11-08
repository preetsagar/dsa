#include <bits/stdc++.h>
using namespace std;
using ld=long double;

int n,k;
vector<int> A,B;
ld esp=1e-9;

ld check(ld mid){
    priority_queue <ld,vector<ld>,greater<ld>> pq;
    for(int i=0; i<n; i++){
        pq.push((A[i]-B[i]*mid));
        if(pq.size()>k) pq.pop();
    }
    ld t=0.0;
    while(!pq.empty()){
        t+=pq.top(); pq.pop();
    }
    return t>=0;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t; while(t--){
        cin>>n>>k;
        A.resize(n);B.resize(n);
        for(int i=0; i<n; i++) cin>>A[i];
        for(int i=0; i<n; i++) cin>>B[i];

        ld lo=0.0,hi=1e8;
        ld ans=0.0;
        while(abs(hi-lo)>esp){
            ld mid=(lo+hi)/2.0;
            if(check(mid)){
                lo=ans=mid;
            }
            else hi=mid;
        }
        cout<<fixed<<setprecision(6)<<ans<<"\n";
    }
    return 0;
}