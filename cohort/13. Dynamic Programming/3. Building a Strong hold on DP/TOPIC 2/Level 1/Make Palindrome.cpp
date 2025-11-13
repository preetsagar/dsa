#include <bits/stdc++.h>
using namespace std;

int t,n;
string str;
int dp[1100][1100];

int rec(int l, int r){
    if(l>=r) return 0;

    if(dp[l][r]!=-1) return dp[l][r];

    int ans = 1e9;
    if(str[l]==str[r]){
        ans = min(ans, rec(l+1, r-1));
    }
    ans = min(ans, 1 + rec(l+1, r));
    ans = min(ans, 1 + rec(l, r-1));

    return dp[l][r] = ans;
}

int main() {
    cin>>t; while(t--){
        cin>>str;
        n = str.size();
        memset(dp, -1, sizeof(dp));
        cout<<rec(0, n-1)<<'\n';
    }
    return 0;
}