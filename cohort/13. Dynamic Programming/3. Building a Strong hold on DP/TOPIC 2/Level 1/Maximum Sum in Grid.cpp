#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m; 
        cin >> n >> m;

        vector<vector<ll>> mat(n, vector<ll>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> mat[i][j];

        if (n > m) {
            vector<vector<ll>> trans(m, vector<ll>(n));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    trans[j][i] = mat[i][j];
            mat.swap(trans);
            swap(n, m);
        }

        ll ans = LLONG_MIN;
        for (int topRow = 0; topRow < n; ++topRow) {
            vector<ll> compressedColumn(m, 0);
            for (int bottomRow = topRow; bottomRow < n; ++bottomRow) {
                for (int j = 0; j < m; ++j) compressedColumn[j] += mat[bottomRow][j];
                ll curr = compressedColumn[0];
                ll localBest = compressedColumn[0];
                for (int j = 1; j < m; ++j) {
                    curr = max(compressedColumn[j], curr + compressedColumn[j]);
                    localBest = max(localBest, curr);
                }
                ans = max(ans, localBest);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}