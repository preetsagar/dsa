#include <bits/stdc++.h>
using namespace std;

int dp[110][110][110];

int t;
string s1,s2,s3;

int solve(int i, int j, int k){
    if(i==-1 || j==-1 || k==-1) return 0;

    if(dp[i][j][k]!=-1) return dp[i][j][k];
    
    int ans = 0;
    if(s1[i]==s2[j] && s2[j]==s3[k]){
        ans = 1 + solve(i-1, j-1, k-1);
    }
    ans = max(ans, solve(i-1, j, k));
    ans = max(ans, solve(i, j-1, k));
    ans = max(ans, solve(i, j, k-1));

    return dp[i][j][k] = ans;
}

int main() {
    cin>>t; while(t--){
        memset(dp, -1, sizeof(dp));
        cin>>s1>>s2>>s3;
        cout<<solve(s1.size()-1,s2.size()-1,s3.size()-1)<<"\n";
    }
    return 0;
}