#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, a, b;
vector<int> arr, dis;
vector<bool> vis, value_used;
map<int, vector<int>> same_value_indices;

void dijkstra(int src) {
    priority_queue<pair<int, int>> pq;
    dis[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;

        if (!value_used[arr[u]]) {  // NOTE If we haven't used this value yet
            for (int v : same_value_indices[arr[u]]) {
                if (dis[v] > dis[u] + a) {
                    dis[v] = dis[u] + a;
                    pq.push({-dis[v], v});
                }
            }
            value_used[arr[u]] = true;
        }

        // Move to adjacent indices
        if (u > 1 && dis[u - 1] > dis[u] + b) {
            dis[u - 1] = dis[u] + b;
            pq.push({-dis[u - 1], u - 1});
        }
        if (u < n && dis[u + 1] > dis[u] + b) {
            dis[u + 1] = dis[u] + b;
            pq.push({-dis[u + 1], u + 1});
        }
    }
}

signed main() {
    cin >> n >> a >> b;
    arr.resize(n + 1);
    dis.assign(n + 1, 1e18);
    vis.assign(n + 1, false);
    value_used.assign(101, false);  // values in arr[i] are from 1 to 100

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        same_value_indices[arr[i]].push_back(i);
    }

    int src;
    cin >> src;

    dijkstra(src);

    for (int i = 1; i <= n; ++i)
        cout << dis[i] << " ";

    return 0;
}