/*
Description
You have given an undirected graph with n nodes, and m edges between them. The goal is to add exactly one edge between two nodes such that the total number of connected components in the graph decreases.
Your task is to find out the number of ways to add such edge.

Input Format
The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1, 2, …, n.
After that, there are m lines describing the edges. Each line has two integers a and b: there is an edge between those nodes.
An edge always connects two different nodes, and there is at most one edge between any two nodes.

Output Format
Print the number of ways to add such edge, described in the statement.

Constraints
1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n

Sample Input 1
5 4
1 2
2 3
1 3
4 5
Sample Output 1
6
Sample Input 2
4 3
1 2
2 3
3 4
Sample Output 2
0


Vivek's Recommended Template (CFFTD) for Problem note making after solving:
 C ( Concept/topic used in the problem) ->  Connected Component
 F ( Framework, questions that would lead to new observations/forms) -> DFS
 F ( Form, which style of problem, as discussed in various topics) ->
 T (Tactics, what misc idea was used to reduce the time complexity/constraint) -> DFS + prefix optimization(Matrix visualization)
 D (Debug issues faced, what to keep in mind next time) -> int to Long long
*/

#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define pii pair<ll, ll>
const int mod = 1e9 + 7;
inline ll add(ll x,ll y) { return ((x + y) % mod + mod) % mod; }
inline ll sub(ll x,ll y) { return ((x - y) % mod + mod) % mod; }

/* #########################################################################################################################
 */

int n,q,m;
ll cnt = 0;
vector<vector<int>> adj;
vector<int> vis;

void DFS(int u,int color) {
    cnt++;
    vis[u] = color;

    for(int v : adj[u]) {
        if(!vis[v]) {
            DFS(v,color);
        }
    }
}

void input() {
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int color = 0;
    vector<ll> tmp;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cnt = 0;
            color++;
            DFS(i,color);
            tmp.push_back(cnt);
        }
    }

    n = tmp.size();
    vector<ll> prefix(n + 1,0);
    prefix[1] = tmp[0];
    for(int i = 2; i <= n; i++) {
        prefix[i] = prefix[i - 1] + tmp[i - 1];
    }

    ll ans = 0;
    for(int i = 2; i <= n; i++) {
        ans += prefix[i - 1] * tmp[i - 1];
    }
    cout << ans << endl;
}

int main() {
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    return 0;
}