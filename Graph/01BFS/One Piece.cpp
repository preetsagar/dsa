#include <bits/stdc++.h>
using namespace std;

int n,m;
using state = pair<int,int>;
vector<vector<int>> mat;
vector<vector<state>> graph;
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
    cin >> n >> m;
    mat.assign(n,vector<int>(m));

    // input matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    // direction
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    // making the graph
    graph.assign((n * m + 1),vector<state>());
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int u = i * m + (j + 1);
            for(int k = 0; k < 4; k++){
                int xx = i + dx[k];
                int yy = j + dy[k];

                if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                int v = xx * m + (yy + 1);

                if(mat[i][j] == k + 1){
                    graph[u].push_back({v,0});
                }
                else{
                    graph[u].push_back({v,1});
                }
            }
        }
    }

    // print the graph
    // for(int i=1; i<=n*m; i++){
    //     cout<<i<<" -> ";
    //     for(state j:graph[i]){
    //         cout<<"("<<j.first<<","<<j.second<<") ";
    //     }
    //     cout<<endl;
    // }

    dist.assign((n * m + 1),1e9);
    BFS01(1);

    cout << dist[n * m];

    return 0;
}