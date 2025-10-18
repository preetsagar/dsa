#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int mat[210][210];
int dp[210][210][410];
int MOD = 1e9 + 7;

int rec(int i, int j, int k){
    if(i<0 || j<0 || k<0) return 0;

    if(i==0 && j==0){
        if(mat[i][j]==0) return 1;
        else if(k>0) return 1;
        else return 0;
    }

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    int ans = 0;
    if(mat[i][j]==0){
        ans = (rec(i-1, j, k)%MOD + rec(i, j-1, k)%MOD)%MOD;
    }
    else{
        ans = (rec(i-1, j, k-1)%MOD + rec(i, j-1, k-1)%MOD)%MOD;
    }

    return dp[i][j][k] = ans;
}


int main() {
    int t; cin>>t; while(t--){
        cin>>n>>m>>k;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>mat[i][j];
            }
        }
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                for (int l=0; l<=k; l++){
                    dp[i][j][l] = -1;
                }
            }
        }
        cout<<rec(n-1, m-1, k)<<'\n';
    }
    return 0;
}