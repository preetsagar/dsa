#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod = 1e9+7;

string a, b, c;
ll dp[110][110][110];

ll solve(ll i, ll j, ll k){
    
    if(i==a.size() || j==b.size() || k==c.size()) return 0;

    if(dp[i][j][k]!=-1) return dp[i][j][k];
    ll ans=0;
    if(a[i]==b[j] && b[j]==c[k])
        ans =  1 + solve(i+1, j+1, k+1);
    
    else{
        ans = max(ans, solve(i+1, j, k));
        ans = max(ans, solve(i, j+1, k));
        ans = max(ans, solve(i, j, k+1));
    }

    return dp[i][j][k] = ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin>>a>>b>>c;
        cout<<solve(0, 0, 0)<<endl;
    }
}