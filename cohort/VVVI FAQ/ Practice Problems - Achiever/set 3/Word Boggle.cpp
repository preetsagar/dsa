
#include <bits/stdc++.h>
using namespace std;

int n, m, w;
char mat[50][50];

vector<string> words;
set<string> ans;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int idx, int wordIdx) {
    if (idx == words[wordIdx].size() - 1) {
        ans.insert(words[wordIdx]);
        return;
    }

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;

        if (mat[nx][ny] != words[wordIdx][idx + 1])
            continue;

        mat[nx][ny] = '#';
        dfs(nx, ny, idx + 1, wordIdx);
        mat[nx][ny] = words[wordIdx][idx + 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        cin >> w;
        words.resize(w);

        for (string& word : words)
            cin >> word;

        sort(words.begin(), words.end());
        ans.clear();

        for (int k = 0; k < w; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] != words[k][0])
                        continue;

                    mat[i][j] = '#';
                    dfs(i, j, 0, k);
                    mat[i][j] = words[k][0];
                }
            }
        }

        for (const string& word : ans)
            cout << word << '\n';

        cout << '\n';
    }

    return 0;
}
