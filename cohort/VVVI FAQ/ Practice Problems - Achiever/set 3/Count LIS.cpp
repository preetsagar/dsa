#include <bits/stdc++.h>
using namespace std;

#define int long long

int t,n;
vector<int> arr;
int dp[1100], countDp[1100];

int mod = 1e9+7;

int solve(int i){
    if(dp[i]!=-1) return dp[i];

    countDp[i]=1;
    dp[i]=1;
    for(int j=0; j<i; j++){
        if(arr[i] > arr[j]){
            if(dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                countDp[i] = countDp[j];
            } else if(dp[j]+1 == dp[i]){
                countDp[i] = (countDp[j] + countDp[i])%mod;
            }
        }
    }
    return dp[i];
}

signed main() {
    cin>>t; while(t--){
        cin>>n;
        arr.resize(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        memset(dp, -1, sizeof(dp));
        memset(countDp, 0, sizeof(countDp));
        
        for(int i=0; i<n; i++) solve(i);

        int LIS=0;
        for(int i=0; i<n; i++) LIS = max(LIS, dp[i]);

        int ans=0;
        for(int i=0; i<n; i++){
            if(dp[i] == LIS){
                ans = (ans + countDp[i]) % mod;
            }
        }

        cout<<ans%mod<<"\n";
    }
    return 0;
}