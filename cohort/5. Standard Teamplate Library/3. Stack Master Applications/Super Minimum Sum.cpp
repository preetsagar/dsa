#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> arr, pse, nse;

signed main() {
    int t; cin>>t;  while(t--){
        cin>>n;
        arr.resize(n);
        pse.resize(n);
        nse.resize(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        for(int i=n-1; i>=0; i--){
            nse[i] = i+1;
            while(nse[i]!=n && arr[i] <= arr[nse[i]]) nse[i] = nse[nse[i]];
        }

        for(int i=0; i<n; i++){
            pse[i] = i-1;
            while(pse[i]!=-1 && arr[i] <= arr[pse[i]]) pse[i] = pse[pse[i]];
        }

        int ans=0;
        for(int i=0; i<n; i++){
            int l = i-pse[i];
            int r = nse[i]-i;

            ans += arr[i]*l*r;
        }
        cout<<ans<<'\n';
    }
    return 0;
}