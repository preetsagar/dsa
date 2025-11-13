#include <bits/stdc++.h>
using namespace std;

int t, n,m,k;
int score[110][110];
int dp[110][110][11];

int rec(int i, int j, int sumModK){
    if(j<0 || j>=m) return -1e9;
    if(i==n){
        if(sumModK==0) return 0;
        return -1e9;
    }

    if(dp[i][j][sumModK]!=-1) return dp[i][j][sumModK];

    int ans = 0;
    ans = max(rec(i+1, j-1, (sumModK+score[i][j])%k)+score[i][j], 
            rec(i+1, j+1, (sumModK+score[i][j])%k)+score[i][j]);

    return dp[i][j][sumModK] = ans;
}

int main() {
    cin>>t; while(t--){
        memset(dp, -1, sizeof(dp));
        cin>>n>>m>>k;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char ch; cin>>ch;
                score[i][j] = ch-'0';
            }
        }
        int ans = -1;
        for(int j=0; j<m; j++){
            ans = max(ans, rec(0, j, 0));
        }
        cout<<ans<<'\n';
    }
    return 0;
}