#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<int> arr(n),nseL(n),nseR(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        nseL[0]=arr[0];
        for(int i=1; i<n; i++){
            nseL[i]=max(arr[i],nseL[i-1]);
        }
        nseR[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--){
            nseR[i]=max(arr[i],nseR[i+1]);
        }

        int ans=0;
        for(int i=0; i<n; i++){
            ans+=(min(nseL[i],nseR[i])-arr[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}