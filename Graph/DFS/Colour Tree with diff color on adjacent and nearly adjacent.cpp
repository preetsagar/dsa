/*
Colour Tree

Description
You have been given a tree with N nodes and N - 1 edges. You want to colour each node, such that no two adjacent nodes (directly connected by an edge) and no two nearly-adjacent nodes (both directly connected to a common node with edges) has the same colour.
Your task is to find the minimum number of colours required to accomplished this.

Input Format
The first line of input contains N. Each of the remaining N−1 lines describes an edge in terms of the two nodes it connects.

Output Format
Print the minimum number of colours require.

Constraints
1 ≤ N ≤ 105

Sample Input 1
4
1 2
4 3
2 3
Sample Output 1
3
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        u = adj[u].size();
        v = adj[v].size();
        ans = max({ans,u,v});
    }
    cout << ans + 1;
    return 0;
}