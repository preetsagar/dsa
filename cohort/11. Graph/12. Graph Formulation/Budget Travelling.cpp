#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
#define MP make_pair

using state = pair<int, int>;

int n, m, A, B, C;

vector<vector<state>> graph;
vector<int> cost;
vector<vector<int>> dis, vis;

void dijkstra(state st){
    // Min-heap priority queue
    priority_queue<pair<int, state>, vector<pair<int, state>>, greater<>> pq;
    pq.push({0, st});
    dis[st.F][st.S] = 0;

    while (!pq.empty()) {
        auto t = pq.top(); pq.pop();
        int currCost = t.F;
        int u = t.S.F;
        int fuelRem = t.S.S;

        if (vis[u][fuelRem]) continue;
        vis[u][fuelRem] = 1;

        for (auto v : graph[u]) {
            int nextNode = v.F;
            int fuelNeeded = v.S;

            if (fuelRem >= fuelNeeded) {
                int newFuel = fuelRem - fuelNeeded;
                if (dis[nextNode][newFuel] > dis[u][fuelRem]) {
                    dis[nextNode][newFuel] = dis[u][fuelRem];
                    pq.push({dis[nextNode][newFuel], {nextNode, newFuel}});
                }
            }
        }

        if (fuelRem < C) {
            int newCost = dis[u][fuelRem] + cost[u];
            if (dis[u][fuelRem + 1] > newCost) {
                dis[u][fuelRem + 1] = newCost;
                pq.push({newCost, {u, fuelRem + 1}});
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    graph.resize(n + 1);
    cost.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++) cin >> cost[i];
    cin >> A >> B >> C;

    dis.assign(n + 1, vector<int>(C + 1, 1e18));
    vis.assign(n + 1, vector<int>(C + 1, 0));

    dijkstra({A, 0});

    int ans = *min_element(dis[B].begin(), dis[B].end());
    cout << (ans == 1e18 ? -1 : ans) << "\n";

    return 0;
}