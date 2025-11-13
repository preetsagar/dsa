#include <bits/stdc++.h>
using namespace std;

int tc,n,k;
int dp[5001][5001];
int mod = 1e9 + 7;

int rec(int n, int k){
    if(n==k || k==1) return 1;
    if(n<k) return 0;

    if(dp[n][k]!=-1) return dp[n][k];

    int ans = 0;
    ans = (ans%mod + rec(n-1, k-1)%mod)%mod;
    ans = (ans%mod + rec(n-k, k)%mod)%mod;

    return dp[n][k] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(dp, -1, sizeof(dp));
    cin>>tc; 
    while(tc--){
        cin>>n>>k;
        if (n <= 0 || k <= 0 || k > n)  { cout << 0 << '\n'; continue; }
       cout<<rec(n,k)<<'\n';
    }
    return 0;
}