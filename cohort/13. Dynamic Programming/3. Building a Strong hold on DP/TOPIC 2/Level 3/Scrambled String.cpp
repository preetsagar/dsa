#include <bits/stdc++.h>
using namespace std;

int tc,n,m;
string s1,s2;
int dp[50][50][50];

int rec(int l1, int l2, int len){

    if(len==1) return s1[l1]==s2[l2];

    if(dp[l1][l2][len]!=-1) return dp[l1][l2][len];

    int ans = 0;
    for(int k=1; k<len;k++){
        // IF NOT SWAP
        ans = ans | (rec(l1, l2, k) && rec(l1+k, l2+k, len-k));
        // IF SWAP
        ans = ans | (rec(l1, l2+len-k, k) && rec(l1+k, l2, len-k));
    }

    return dp[l1][l2][len] = ans;
}

int main() {
    cin>>tc; while(tc--){
        cin>>s1>>s2;
        n = s1.size();
        m = s2.size();
        memset(dp, -1, sizeof(dp));
        if(n!=m) cout<<"No\n";
        memset(dp, -1, sizeof(dp));
        cout<<(rec(0, 0, n) ? "Yes\n" : "No\n");
    }
    return 0;
}