#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MP make_pair

int n;
vector<pair<int, pair<int, int>>> jobs;
vector<int> dp;

bool comp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
    return a.first < b.first;
}

int rec(int level) {
    if(level >= n) return 0;
    if(dp[level] != -1) return dp[level];

    int ans = rec(level + 1); 
    int nextJob = upper_bound(jobs.begin(), jobs.end(), 
        MP(jobs[level].second.first, MP(-1e18, -1e18)), comp)-jobs.begin();
    ans = max(ans, jobs[level].second.second + rec(nextJob));

    return dp[level] = ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    jobs.resize(n);
    dp.assign(n, -1);
    for(int i=0; i<n; i++){
        int a,b,p; cin >> a >> b >> p;
        jobs[i] = {a, {b, p}};
    }
    sort(jobs.begin(), jobs.end());

    cout << rec(0) << "\n";
    return 0;
}
