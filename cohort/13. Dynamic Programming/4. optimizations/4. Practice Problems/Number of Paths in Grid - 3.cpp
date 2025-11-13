#include <bits/stdc++.h>
using namespace std;

#define int long long

int mod = 1e9+7;
int tc, n, m, K;
int arr[210][210];
int dp[210][210][210];

int rec(int i, int j, int k){
    if(k<0) return 0;
    if(i<0 || j<0) return 0;
    if(arr[i][j]==1) return 0;
    if(i==0 && j==0) return 1;

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    int ans = 0;
    ans = rec(i, j-1, k-1);
    ans += rec(i-1, j, K);

    return dp[i][j][k] = ans%mod;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    cin>>tc; while(tc--){
        cin>>n>>m>>K;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int x=0; x<=K; x++) dp[i][j][x] =  -1;
            }
        }
        cout<<(rec(n-1, m-1, K)%mod)<<'\n';

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         for(int x=0; x<=K; x++) dp[i][j][x] =  0;
        //     }
        // }
        // if(arr[0][0]==0) dp[0][0][0] = 1;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(arr[i][j]==1) continue;

        //         for(int x=0; x<=K; x++){
        //             if(i>0) dp[i][j][0] += dp[i-1][j][x];
        //             if(x>0 && j>0) dp[i][j][x] += dp[i][j-1][x-1];
                    

        //             dp[i][j][x] = dp[i][j][x] % mod;
        //         }
        //     }
        // }

        // int result = 0;
        // for (int x = 0; x <= K; ++x) {
        //     result = (result + dp[n-1][m-1][x]) % mod;
        // }
        // cout << result << '\n';

    }
    return 0;
}