#include <bits/stdc++.h>
using namespace std;

#define int long long

int t,n;
vector<int> arr;
int dp[1100], countDp[1100];

int mod = 1e9+7;

int solve(int i){
    if(dp[i]!=-1) return dp[i];

    int ans = 1;
    for(int j=0; j<i; j++){
        if(arr[i] > arr[j]){
            ans = max(ans, solve(j)+1);
        }
    }
    return dp[i] = ans;
}

int count(int i){
    if(solve(i)==1) return 1;

    if(countDp[i]!=-1) return countDp[i];

    int ans = 0;
    for(int j=0; j<i; j++){
        if(arr[i] > arr[j] && solve(i)==solve(j)+1){
            ans = (ans + count(j)) % mod;
        }
    }
    return countDp[i] = ans;
}


signed main() {
    cin>>t; while(t--){
        cin>>n;
        arr.resize(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        memset(dp, -1, sizeof(dp));
        memset(countDp, -1, sizeof(countDp));
        for(int i=0; i<n; i++) solve(i);

        int LIS=0;
        for(int i=0; i<n; i++) LIS = max(LIS, dp[i]);

        int ans=0;
        for(int i=0; i<n; i++){
            if(dp[i]==LIS){
                ans += count(i);
            }
        }
        
        // for(int i=0; i<n; i++) cout<<dp[i]<<" ";
        // cout<<"\n";

        cout<<ans%mod<<"\n";
    }
    return 0;
}