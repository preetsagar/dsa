#include <bits/stdc++.h>
using namespace std;

#define int long long

int t, n, m;
int mat[210][210];
int dp[210][210];

// dp[i][j] = min health needed to reach bottom-right from (i, j)
int solve(int i, int j){
    if(i>=n || j>=m) return 1e9;
    if(i==n-1 && j==m-1){
        return max(1ll, 1ll-mat[i][j]);
    }

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 1e9;
    ans = min(ans, solve(i, j+1)-mat[i][j]);
    ans = min(ans, solve(i+1, j)-mat[i][j]);

    return dp[i][j]=max(ans, 1ll);
}


signed main() {
    cin>>t; while(t--){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>mat[i][j];
            }
        }
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j] = -1;
            }
        }
        
        cout<<solve(0, 0)<<"\n";
    }
    return 0;
}