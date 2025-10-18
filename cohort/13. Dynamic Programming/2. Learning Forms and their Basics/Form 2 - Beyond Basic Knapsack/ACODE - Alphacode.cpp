#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,k;
string str;
int dp[5100];

int rec(int level){
    if(level == n) return 1;
    if(str[level]=='0') return 0;
    
    if(dp[level]!=-1) return dp[level];
    
    int ans = 0;
    if(!(level+1 < n && str[level+1]=='0')) ans += rec(level+1);
    if(level+1 < n){
        int num = (str[level]-'0')*10 + (str[level+1]-'0');
        if(num >0 && num <27){
            ans += rec(level+2);
        }
    }
    
    return dp[level] = ans;
}

signed main()
{
    while(cin>>str){
        memset(dp, -1, sizeof(dp));
        n = str.size();
        if(rec(0)!=0) cout<<rec(0)<<'\n';
    }
    return 0;
}