#include <bits/stdc++.h>
using namespace std;

int tc, n, m;
string s,t;
map<char, vector<int>> mp;
int dp[1001][1001], nxt[1001][1001];

int rec(int i, int j){
    if(i==n) return 1e9;
    if(j==m) return 1;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 1e9;
    if(nxt[i][j]==-1) ans = 1;
    else{
        ans = min(ans, rec(i+1, nxt[i][j]+1)+1);
    }
    ans = min(ans, rec(i+1, j));

    return dp[i][j] = ans;
}

int main() {
    cin>>tc; while(tc--){
        cin >> s >> t;
        n = s.size(), m = t.size();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) {
            int p = -1;
            for (int j = m-1; j>=0; j--) {
                if (s[i] == t[j])p = j;
                nxt[i][j] = p;
            }
        }
        int ans = rec(0, 0);
        if (ans > n)ans = -1;
        cout << ans << endl;
    }
    return 0;
}