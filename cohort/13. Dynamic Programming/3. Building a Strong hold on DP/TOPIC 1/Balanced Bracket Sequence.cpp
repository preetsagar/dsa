#include <bits/stdc++.h>
using namespace std;

int t, n;
string str;
int MOD = 1e9+7;
int dp[1100][1100];

int rec(int level, int leftB){
    // pruning
    if(level-leftB > leftB) return 0;
    // base case
    if(level==n){
        if(n-leftB==leftB) return 1;
        return 0;
    }

    if(dp[level][leftB]!=-1) return dp[level][leftB];

    int ans = 0;
    if(str[level]=='('){
        ans = (ans%MOD + rec(level+1, leftB+1)%MOD)%MOD;
    }else if(str[level]==')'){
        ans = (ans%MOD + rec(level+1, leftB)%MOD)%MOD;
    }else{
        ans = (ans%MOD + rec(level+1, leftB+1)%MOD)%MOD;
        ans = (ans%MOD + rec(level+1, leftB)%MOD)%MOD;
    }
    
    return dp[level][leftB] = ans;
}

int main() {
    cin>>t; while(t--){
        cin>>str;
        n = str.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) dp[i][j] = -1;
        }
        cout<<rec(0, 0)<<'\n';
    }
    return 0;
}