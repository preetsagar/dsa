/*Easy Graph Queries
Hard

Description
You have given an undirected graph G with N nodes and M edges. You've to answer
Q queries. Each query is either of the following two types:

1 X: Print the size of the connected components containing node X.
2 X Y: Print ‘YES’ (without quotes) if node X and Y belong to the same connected
component, else print ‘NO’ (without quotes). Input Format The first line of
input contains three space-separated integers N, M, and Q (1 ≤ N, M, Q ≤ 105).
Next M lines contain two space-separated integers u and v (1 ≤ u, v ≤ N).
Each of the next Q lines contains queries of one of the types as described in
the statement.

Output Format
Print Q lines as the answer to the Q queries, each on a new line.

Constraints
Sample Input 1
6 5 5
1 2
2 3
1 3
4 4
5 6
1 2
1 4
2 3 4
1 5
2 5 6
Sample Output 1
3
1
NO
2
YES */

#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define pii pair<ll, ll>
const int mod = 1e9 + 7;
inline ll add(ll x, ll y) { return ((x + y) % mod + mod) % mod; }
inline ll sub(ll x, ll y) { return ((x - y) % mod + mod) % mod; }

/* #########################################################################################################################
 */

ll n, q, m;
vector<vector<int>> adj;
vector<int> vis;

void DFS(int u, int color) {
    vis[u] = color;

    for (int v : adj[u]) {
        if (!vis[v]) {
            DFS(v, color);
        }
    }
}

void input() {
    cin >> n >> m >> q;
    adj.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int color = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            color++;
            DFS(i, color);
        }
    }

    map<int, int> _map;
    for (int i = 1; i <= n; i++) {
        _map[vis[i]]++;
    }

    for (int i = 0; i < q; i++) {
        int ch;
        cin >> ch;

        if (ch == 1) {
            int a;
            cin >> a;
            cout << _map[vis[a]] << endl;
        } else {
            int a, b;
            cin >> a >> b;
            if (vis[a] == vis[b]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    return 0;
}