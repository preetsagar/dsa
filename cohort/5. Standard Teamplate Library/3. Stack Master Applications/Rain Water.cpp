#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<int> arr(n), lb(n), rb(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        lb[0] = arr[0];
        for(int i=1; i<n; i++){
            lb[i] = max(lb[i-1], arr[i]);
        }

        rb[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            rb[i] = max(rb[i+1], arr[i]);
        }

        int ans=0;
        for(int i=0; i<n; i++){
            int t = min(lb[i], rb[i]) - arr[i];
            ans += t;
        }
        cout<<ans<<'\n';
    }
    return 0;
}