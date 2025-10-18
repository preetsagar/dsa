#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9+7;

signed main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        int arr[1100];
        for(int i=0; i<n; i++) cin>>arr[i];

        int dp[1100];
        int countLis[1100];

        for(int i = 0; i < n; i++){
            dp[i] = 1;
            countLis[i] = 1;
        }
        
        dp[0] = 1;
        countLis[0] = 1;

        for(int i=1; i<n; i++){
            dp[i] = 1;
            for(int j=0; j<i; j++){
                if(arr[i] > arr[j]){
                    if(dp[j]+1 > dp[i]){
                        countLis[i] = countLis[j];
                        dp[i] = dp[j]+1;
                    }
                    else if(dp[j]+1 == dp[i]){
                        countLis[i] = (countLis[i] + countLis[j])%MOD;
                    }
                }
            }
        }

        int ans = 0, len=0;
        for(int i=0; i<n; i++){
            if(len < dp[i]){
                len = dp[i];
                ans = countLis[i];
            }
            else if(len == dp[i]){
                ans = (ans + countLis[i])%MOD;
            }
        }
        cout<<ans%MOD<<"\n";
    }
    return 0;
}