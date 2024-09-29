#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main() {
    int t; cin>>t; while(t--){
        int n,k; cin>>n>>k;
        map<int,int> m;
        int count=0;
        for(int i=0; i<n; i++){
            int t; cin>>t;
            if(m.find(t-k)!=m.end()) count+=m[t-k];
            if(m.find(t+k)!=m.end()) count+=m[t+k];

            m[t]++;
        }
        cout<<count<<"\n";
    }
    return 0;
}