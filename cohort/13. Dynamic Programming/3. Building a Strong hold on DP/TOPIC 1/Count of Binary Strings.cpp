#include <bits/stdc++.h>
using namespace std;

int t, n;
int MOD = 1e9+7;
int dp[1100000][6];

int rec(int level, int match){
    if(match==4) return 0;
    if(level==0) return 1;

    if(dp[level][match]!=-1) return dp[level][match];

    int ans = 0;
    if(match==0){
        ans = (rec(level-1, 1)%MOD + rec(level-1, 0)%MOD)%MOD;
    }else if(match==1){
        ans = (rec(level-1, 1)%MOD + rec(level-1, 2)%MOD)%MOD;
    }else if(match==2){
        ans = (rec(level-1, 3)%MOD + rec(level-1, 0)%MOD)%MOD;
    }else if(match==3){
        ans = (rec(level-1, 4)%MOD + rec(level-1, 2)%MOD)%MOD;
    }

    return dp[level][match] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin>>t; while(t--){
        cin>>n;
        cout<<rec(n, 0)<<'\n';
    }
    return 0;
}