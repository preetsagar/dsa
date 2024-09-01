#include <bits/stdc++.h>
using namespace std;

using ll=long long;
ll graph[505][505];
int n;
vector<int> nodes,ans;

int main() {
    cin>>n;

    // input of adjacency matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>graph[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        int node;
        cin>>node;
        node--;
        nodes.push_back(node);
    }
    reverse(nodes.begin(),nodes.end());

    // Floyd Warshall
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                graph[i][j]=min(graph[i][j],graph[i][nodes[k]]+graph[nodes[k]][j]);
            }
        }

        // jo jo nodes discover hue hai ussi ka shortest path ka sum lena hai
        ll tmp=0;
        for(int i=0; i<=k; i++){
            for(int j=0; j<=k; j++){
                tmp+=graph[nodes[i]][nodes[j]];
            }
        }
        ans.push_back(tmp);
    }
    reverse(ans.begin(),ans.end());
    for(int i:ans) cout<<i<<" ";
    return 0;
}