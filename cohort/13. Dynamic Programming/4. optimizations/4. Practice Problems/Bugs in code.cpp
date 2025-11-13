#include <bits/stdc++.h>
using namespace std;

int n,m,b;
int arr[501];
int MOD = 1e9+7;
#define int long long

int dp[2][501][501];

int rec(int level, int bugs, int lines){
    if(bugs<0 || lines<0) return 0;

    if(level==-1){
        if(bugs>=0 && lines==0) return 1;
        return 0;
    }

    if(dp[level][bugs][lines]!=-1) return dp[level][bugs][lines];

    int ans = 0;
    ans += rec(level, bugs-arr[level], lines-1);
    ans += rec(level-1, bugs, lines);

    return dp[level][bugs][lines] = ans%MOD;
}

signed main() {
    cin>>n>>m>>b;
    for(int i=0; i<n; i++) cin>>arr[i];

    memset(dp, 0, sizeof(dp));
    dp[0][0][0]=1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            for(int k=0; k<=b; k++){
                dp[i%2][j][k] = dp[(i-1)%2][j][k];
                if(j && k-arr[i-1] >= 0)
                    dp[i%2][j][k] += dp[i%2][j-1][k-arr[i-1]];
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=b; i++){
        ans += dp[n%2][m][i];
    }
    cout<<ans%MOD;

    return 0;
}