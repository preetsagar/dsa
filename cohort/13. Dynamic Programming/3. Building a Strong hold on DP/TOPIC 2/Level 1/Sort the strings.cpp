#include <bits/stdc++.h>
using namespace std;

#define int long long

int tc,n;
vector<int> cost;
vector<string> s, revs;
vector<vector<int>> dp;

int rec(int level, int r){
    if(level==n){
        return 0;
    }

    if(dp[level][r]!=-1) return dp[level][r];

    int ans = 1e18;
    string last = r==1 ? revs[level-1] : s[level-1];
        
    if(s[level] >= last){
        ans = min(ans, rec(level+1, 0));
    }
    if(revs[level] >= last){
        ans = min(ans, rec(level+1, 1) + cost[level]);
    }

    return dp[level][r] = ans;
}

signed main() {
    cin>>tc; while(tc--){
        cin>>n;
        cost.assign(n+1, 0);
        s.assign(n+1, "");
        revs.assign(n+1, "");
        dp.assign(n+1, vector<int>(3,-1));
        
        for(int i=0; i<n; i++) cin>>cost[i];
        for(int i=0; i<n; i++) cin>>s[i];

        for(int i=0; i<n; i++){
            revs[i] = s[i]; reverse(revs[i].begin(), revs[i].end());
        }

        int ans = min(rec(1, 0), rec(1,1)+cost[0]);
        cout<< (ans==1e18 ? -1 : ans) <<'\n';
    }
    return 0;
}