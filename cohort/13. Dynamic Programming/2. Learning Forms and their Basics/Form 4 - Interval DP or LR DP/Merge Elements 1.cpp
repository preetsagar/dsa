#include <bits/stdc++.h>
using namespace std;

int n;
int arr[510];
int prefix[510];

int dp[510][510];

int rec(int l, int r){
    if(l==r) return 0;

    if(dp[l][r]!=-1) return dp[l][r];

    int ans = 1e9;
    for(int i=l; i<=r-1; i++){
        int x = (prefix[i]-prefix[l-1])%100;
        int y = (prefix[r]-prefix[i])%100;
        ans = min(ans, rec(l, i) + rec(i+1, r) + x * y);
    }
    return dp[l][r] = ans;
}

int main() {
    cin>>n;
    memset(prefix, 0, sizeof(prefix));
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }
    cout<<rec(1, n);
    return 0;
}