#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[510][510];

int rec(int i, int j){
    // pruning
    // base case
    if(i == s1.size()) return s2.size() - j;
    if(j == s2.size()) return s1.size() - i;

    if(dp[i][j]!=-1) return dp[i][j];

    // transaction
    int ans = 1e9;
    if(s1[i]==s2[j]) ans = min(ans, rec(i+1, j+1));
    ans = min(ans, 1 + rec(i+1, j)); // delete
    ans = min(ans, 1 + rec(i, j+1)); // insert
    ans = min(ans, 1 + rec(i+1, j+1)); // replace

    return dp[i][j] = ans;
}

int main() {
    cin>>s1>>s2;
    memset(dp, -1, sizeof(dp));
    cout<<rec(0,0)<<'\n';
    return 0;
}