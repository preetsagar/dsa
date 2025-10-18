#include <bits/stdc++.h>
using namespace std;

int n;
int arr[110];
int dp[110][110];

int rec(int l, int r){
    if(l>=r) return 1;

    if(dp[l][r]!=-1) return dp[l][r];

    int ans = 1e9;
    if(arr[l]==arr[r]){
        ans = min(ans, rec(l+1, r-1));
    }
    for(int mid=l; mid<r; mid++){
        if(arr[l]==arr[mid]){
            ans = min(ans, rec(l+1, mid-1) + rec(mid+1, r));
        }
    }

    return dp[l][r] = ans;
}

int main() {
    int t; cin>>t; while(t--){
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        memset(dp, -1, sizeof(dp));
        cout<<rec(0, n-1)<<'\n';
    }
    return 0;
}