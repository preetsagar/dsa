#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9+7;

int n,m;
string str[501];
int dp[501][501][501];

int rec(int x1, int y1, int x2, int y2){
    if(x1 > x2 || y1 > y2) return 0;
    if(str[x1][y1] != str[x2][y2]) return 0;
    if(x1 == x2 && y1 == y2) return 1;
    if(x1 == x2 && y1+1 == y2) return 1;
    if(x1+1 == x2 && y1 == y2) return 1;

    if(dp[y1][x2][y2] != -1) return dp[y1][x2][y2];

    int ans = 0;
    ans += rec(x1 + 1, y1, x2 - 1, y2);
    ans += rec(x1, y1 + 1, x2 - 1, y2);
    ans += rec(x1 + 1, y1, x2, y2 - 1);
    ans += rec(x1, y1 + 1, x2, y2 - 1);
    ans %= MOD;

    return dp[y1][x2][y2] = ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> str[i];

    cout << rec(0, 0, n-1, m-1) << "\n";
    return 0;
}
