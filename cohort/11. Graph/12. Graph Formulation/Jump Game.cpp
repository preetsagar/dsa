#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

const int mx = 2e5 + 10;

int n, a, b;
int arr[mx];
vector<vector<array<int, 2>>> adj;
map<int, vector<int>> sadj; // same value index list.
vector<ll> dist;
void dijktra(int src) { // ~O(NlogN)
	dist.assign(2 * n + 10, 1e18); // now we have 2*n nodes.
	priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2> >> pq;
	pq.push({0, src});
	dist[src] = 0;
	while (!pq.empty()) {
		auto x = pq.top();
		pq.pop();
		int i = x[1];
		if (x[0] > dist[i])continue;
		for (auto y : adj[i]) {
			int j = y[0], w = y[1];
			if (dist[j] > dist[i] + w) {
				dist[j] = dist[i] + w;
				pq.push({dist[j], j});
			}
		}
	}
}
void solve() {
	cin >> n;
	cin >> a >> b;
	adj.assign(2 * n + 10, vector<array<int, 2>>());
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sadj[arr[i]].push_back(i);
		if (i != n)adj[i].push_back({i + 1, b});
		if (i != 1)adj[i].push_back({i - 1, b});
	}
	int super_node = n + 1;
	for (auto x : sadj) {
		for (auto i : x.second) {
			adj[super_node].push_back({i, a});
			adj[i].push_back({super_node, 0});
		}
		super_node++;
	}// now we have at max 2*n nodes in the graph and 4*n-2 edges.
	int src;
	cin >> src;
	dijktra(src);
	for (int i = 1; i <= n; i++)cout << dist[i] << " ";
}
int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	// int i = 1;
	// cin >> t;
	while (t--) {
		// cout << "Case #" << i << ": ";
		solve();
		// i++;
	}
	return 0;
}