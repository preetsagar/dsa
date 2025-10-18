#include <bits/stdc++.h>
using namespace std;

#define int long long

int t, n, arr[110000];
string str;
string matchStr = "hard";

int dp[110000][10];

int rec(int i, int m){
    if(m==4) return 1e18;
    if(i==n) return 0;

    if(dp[i][m]!=-1) return dp[i][m];

    int ans = 1e18;
    if(str[i]==matchStr[m]){
        ans = min(ans, rec(i+1, m) + arr[i]);
        ans = min(ans, rec(i+1, m+1));
    }
    else{
        ans = min(ans, rec(i+1, m));
    }

    return dp[i][m] = ans;
}

signed main() {
    cin>>t; while(t--){
        cin>>n>>str;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        // memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            for(int j=0; j<5; j++){
                dp[i][j] = -1;
            }
        }
        cout<<rec(0, 0)<<'\n';
    }
    return 0;
}