#include <bits/stdc++.h>
using namespace std;

#define int long long

int tc, n, k;
vector<int> freq;
unordered_map<int, int> mp;
int MOD = 1e9+7;
int dp[2000][2000];

int rec(int level, int x){
    if(x>k) return 0;
    if(level==-1) return 1;

    if(dp[level][x]!=-1) return dp[level][x];

    int ans = 0;
    ans += rec(level-1, x);
    ans += (freq[level] * rec(level-1, x+1));

    return dp[level][x] = ans%MOD;
}

signed main() {
    cin>>tc;
    while(tc--){
        cin>>n>>k;
        mp.clear(); freq.clear();
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            int x; cin>>x;
            mp[x]++;
        }
        for(auto it:mp) freq.push_back(it.second);
        cout<<rec(freq.size()-1, 0)<<'\n';
    }
    return 0;
}