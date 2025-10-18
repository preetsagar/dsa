#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int arr[3100];
int dp[3100][3100];

int rec(int l, int r){
    if(l==r) return arr[l];
    
    if(dp[l][r]!=-1e18) return dp[l][r];

    int ans = -1e18;
    ans = max(ans, arr[l] - rec(l+1, r));
    ans = max(ans, arr[r] - rec(l, r-1));
    
    return dp[l][r] = ans;
}

signed main() {
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = -1e18;
        }
    }
    cout<<rec(0, n-1);
    return 0;
}