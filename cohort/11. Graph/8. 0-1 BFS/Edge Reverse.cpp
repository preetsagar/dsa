#include <bits/stdc++.h>
using namespace std;

int n,m,t;
vector<vector<pair<int, int>>> graph;
vector<int> dis;

void bfs01(int st){
    deque<int> dq;
    dq.push_front(st);
    dis[st]=0;

    while(!dq.empty()){
        int u = dq.front(); dq.pop_front();
        for(auto v:graph[u]){
            if(dis[v.first] > dis[u]+v.second){
                if(v.second==0) dq.push_front(v.first);
                else dq.push_back(v.first);

                dis[v.first] = dis[u] + v.second;
            }
        }
    }
}

int main() {
    cin>>t;while(t--){
        graph.clear();
        dis.clear();
        cin>>n>>m;
        graph.resize(n+1);
        dis.assign(n+1, 1e9);
        for(int i=0; i<m; i++){
            int u,v; cin>>u>>v;
            graph[u].push_back({v, 0});
            graph[v].push_back({u, 1});
        }

        bfs01(1);
        if (dis[n] == 1e9)cout << -1<<endl;
	    else cout << dis[n]<<endl;
    }

    return 0;
}