#include <bits/stdc++.h>
using namespace std;

int n,m;
using pii = pair<int,int>;
vector<vector<pii>> graph;
vector<int> dist;

void BFS01(int st){
    deque<int> dq;
    dist[st] = 0;
    dq.push_front(st);

    while(!dq.empty()){
        int u = dq.front();
        dq.pop_front();

        for(auto v : graph[u]){
            int node = v.first;
            int wight = v.second;

            if(dist[node] > dist[u] + wight){
                dist[node] = dist[u] + wight;

                if(wight == 0){
                    dq.push_front(node);
                }
                else{
                    dq.push_back(node);
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        graph.assign(n + 1,vector<pii>());
        dist.assign(n + 1,1e9);

        for(int i = 0; i < m; i++){
            int a,b;
            cin >> a >> b;
            graph[a].push_back({b,0}); // forward edge with cost 0
            graph[b].push_back({a,1}); // backward edge with cost 1
        }

        BFS01(1);
        if(dist[n] == 1e9)cout << -1 << endl;
        else cout << dist[n] << endl;
    }
    return 0;
}