#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;cin >> t;while (t--) {
        int k; cin >> k;

        vector<vector<int>> lists(k);

        for (int i = 0; i<k; i++) {
            int n; cin >> n;

            lists[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> lists[i][j];
            }
        }

        // {negative value, {list index, element index}}
        priority_queue<pair<int, pair<int, int>>> pq;

        int mx = INT_MIN;

        for (int i = 0; i < k; i++) {
            mx = max(mx, lists[i][0]);
            pq.push({-lists[i][0], {i, 0}});
        }

        int ansL = INT_MAX, ansR = INT_MAX;
        int ansLen = INT_MAX;

        while (true) {
            auto [negVal, info] = pq.top();
            pq.pop();

            int val = -negVal;
            int listIdx = info.first;
            int pos = info.second;

            if (mx - val < ansLen) {
                ansLen = mx - val;
                ansL = val;
                ansR = mx;
            }

            if (pos + 1 == lists[listIdx].size()) {
                break;
            }

            int nextVal = lists[listIdx][pos + 1];
            mx = max(mx, nextVal);

            pq.push({-nextVal, {listIdx, pos + 1}});
        }

        cout << ansL << " " << ansR << '\n';
    }

    return 0;
}