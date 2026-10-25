#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr, leftLIS, rightLIS, dp;

// int solve(int i){
//     if(dp[i]!=-1) return dp[i];

//     dp[i]=1;
//     for(int j=0; j<i; j++){
//         if(arr[i] > arr[j]){
//             dp[i] = max(dp[i], dp[j]+1);
//         }
//     }

//     return dp[i];
// }

void solve(){
    vector<int> lis;

    for(int i=0; i<n; i++){
        if(lis.empty() || lis.back() < arr[i]){
            lis.push_back(arr[i]);
        }else{
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
        }

        dp[i] = lis.size();
    }
}

int main() {
    int t; cin>>t; while(t--){
        cin>>n;
        arr.resize(n);
        leftLIS.resize(n);
        rightLIS.resize(n);
        dp.resize(n);

        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        fill(dp.begin(), dp.end(), -1);
        solve();
        for(int i=0; i<n; i++) leftLIS[i] = dp[i];

        fill(dp.begin(), dp.end(), -1);
        reverse(arr.begin(), arr.end());
        solve();
        reverse(dp.begin(), dp.end());


        int ans = -1;
        for(int i=1; i<n-1; i++){
            if(leftLIS[i]==1 || dp[i]==1) continue;
            ans = max(ans, leftLIS[i]+dp[i]-1);
        }

        cout << (ans == -1 ? ans : n - ans) << "\n";
    }
    return 0;
}