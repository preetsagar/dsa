#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,k;
int height[110000];
int dp[110000];

int rec(int level){
    if(level == 0) return 0;
    
    if(dp[level]!=-1) return dp[level];
    
    int ans = 1e18;
    for(int ii=level-1; ii>=max(0ll, level-k); ii--){
        ans = min(ans, rec(ii) + abs(height[ii] - height[level]));
    }
    
    return dp[level] = ans;
}

signed main()
{
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>height[i];
    memset(dp, -1, sizeof(dp));
    cout<<rec(n-1);
    return 0;
}