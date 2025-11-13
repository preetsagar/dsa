#include <bits/stdc++.h>
using namespace std;

int n;
int arr[110];
int dp[110][110][110];

int rec(int l, int r, int x){
    if(l>r) return 0;

    if(dp[l][r][x]!=-1) return dp[l][r][x];

    int ans = -1e9;
    ans = max(ans, rec(l+1,r, 0) + (x+1)*(x+1));
    for(int mid=l+1; mid<=r; mid++){
        if(arr[l]==arr[mid]){
            ans = max(ans, rec(l+1, mid-1, 0) + rec(mid, r, x+1));
        }
    }

    return dp[l][r][x] = ans;
}

int main() {
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<rec(0, n-1, 0);
    return 0;
}