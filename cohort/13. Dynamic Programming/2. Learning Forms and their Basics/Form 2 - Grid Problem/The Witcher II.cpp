#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int mat[210][210];
int dp[210][210];
int MOD = 1e9 + 7;

int rec(int i, int j){
    if(i>=n || j>=m) return 1e9;

        if(i==n-1 && j==m-1){
            if(mat[i][j] > 0) return 1;
            else return 1-mat[i][j];
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 1e9;
        ans = min(ans, rec(i+1, j) - mat[i][j]);
        ans = min(ans, rec(i, j+1) - mat[i][j]);

        ans = max(ans, 1);

        return dp[i][j] = ans;
}


int main() {
    int t; cin>>t; while(t--){
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
        cout<<rec(0, 0)<<'\n';
    }
    return 0;
}