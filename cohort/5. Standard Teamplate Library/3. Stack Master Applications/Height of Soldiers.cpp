#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<int> arr(n),nseL(n),nseR(n),ans(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        for(int i=0; i<n; i++){
            nseL[i]=i-1;
            while(nseL[i]!=-1&&arr[i]<=arr[nseL[i]]) nseL[i]=nseL[nseL[i]];
        }

        for(int i=n-1; i>=0; i--){
            nseR[i]=i+1;
            while(nseR[i]!=n&&arr[i]<=arr[nseR[i]]) nseR[i]=nseR[nseR[i]];
        }

        for(int i=0; i<n; i++){
            int l=(nseR[i]-nseL[i]-2);
            ans[l]=max(ans[l],arr[i]);
        }

        for(int i=n-2; i>=0; i--){
            ans[i]=max(ans[i],ans[i+1]);
        }

        for(int i:ans) cout<<i<<" ";
        cout<<"\n";

    }
    return 0;
}
