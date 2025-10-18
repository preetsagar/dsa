#include <bits/stdc++.h>
using namespace std;

int n,m;
int mat[1100][1100];
int dp[1100][1100];

int rec(int i, int j){
    if(i<0 || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 0;
    if(mat[i][j]==1){
        ans = 1 + min(rec(i-1, j), min(rec(i-1, j-1), rec(i, j-1)));
    }

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

        // memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dp[i][j] = -1;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                rec(i, j);
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, dp[i][j]);
            }
        }
        cout<<ans * ans<<'\n';
    }
    return 0;
}