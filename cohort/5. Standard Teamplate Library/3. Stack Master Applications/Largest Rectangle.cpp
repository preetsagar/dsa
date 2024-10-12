#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<int> arr(n),nseL(n),nseR(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        for(int i=0; i<n; i++){
            nseL[i]=i-1;
            while(nseL[i]!=-1&&arr[i]<=arr[nseL[i]]) nseL[i]=nseL[nseL[i]];
        }
        for(int i=n-1; i>=0; i--){
            nseR[i]=i+1;
            while(nseR[i]!=n&&arr[i]<=arr[nseR[i]]) nseR[i]=nseR[nseR[i]];
        }

        int ans=LLONG_MIN;
        for(int i=0; i<n; i++){
            ans=max(ans,arr[i]*(nseR[i]-nseL[i]-1));
        }
        cout<<ans<<"\n";
    }
    return 0;
}