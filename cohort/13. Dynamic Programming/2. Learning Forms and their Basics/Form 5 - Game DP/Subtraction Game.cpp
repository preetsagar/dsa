#include <bits/stdc++.h>
using namespace std;

int n;
int dp[210000];

int rec(int x){
    if(x==0) return 0;
    
    if(dp[x]!=-1) return dp[x];
    
    int ans = 0;
    for(int m=0; (1<<m)<=x; m++){
        if(rec(x-(1<<m))==0){
            ans=1; break;
        }
    }
    return dp[x] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));  // cache across multiple test cases
    int t; cin>>t; while(t--){
        cin>>n;
        if(rec(n)) cout<<"Vivek"<<'\n';
        else cout<<"Abhishek"<<'\n';
    }
    
    return 0;
}