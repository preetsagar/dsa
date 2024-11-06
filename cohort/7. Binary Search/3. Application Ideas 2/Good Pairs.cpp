#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;cin>>t; while(t--){
        int n; cin>>n;
        vector<int> A(n),B(n),C(n);
        for(int i=0; i<n; i++) cin>>A[i];
        for(int i=0; i<n; i++) cin>>B[i];
        for(int i=0; i<n; i++) C[i]=A[i]-B[i];
        sort(C.begin(),C.end());
        int ans=0;
        for(int i=0; i<n; i++){
            int count=C.end()-upper_bound(C.begin()+i+1,C.end(),-C[i]);
            ans+=count;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

// -3 -3 -1 1 4