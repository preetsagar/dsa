#include <bits/stdc++.h>
using namespace std;

int tc, k, m;
int cost[30][30];
string str;
int dp[110][110][30];

int rec(int level, int k, int last) {
    if (k < 0) return -1e9;
    if (level == -1) return 0;
    if (dp[level][k][last] != -1) return dp[level][k][last];

    int ans = -1e9;
    for (int c = 0; c < 26; ++c) {
        int rem = k - (c != (str[level] - 'a'));
        ans = max(ans, cost[c][last] + rec(level - 1, rem, c));
    }
    return dp[level][k][last] = ans;
}

int main() {
    cin >> tc;
    while (tc--) {
        cin >> str >> k >> m;
        memset(cost, 0, sizeof(cost));
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < m; i++) {
            char a, b;
            int c;
            cin >> a >> b >> c;
            cost[a - 'a'][b - 'a'] = c;
        }
        int n = str.size();
        int ans = -1e9;
        // for (int i = 0; i < 26; i++) {
        //     int rem = k - (i != (str[n - 1] - 'a'));
        //     ans = max(ans, rec(n - 2, rem, i));
        // }
        ans = rec(n-1, k, 27);
        cout << ans << '\n';
    }
    return 0;
}
