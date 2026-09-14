#include <bits/stdc++.h>
using namespace std;

int mat[1100][1100];
int dis[1100][1100];
int n, m;

vector<pair<int, int>> neighbour(pair<int, int> u){
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    vector<pair<int, int>> neig;
    for(int i=0; i<4; i++){
        int vx = u.first + dx[i];
        int vy = u.second + dy[i];

        if(vx >=0 && vx<n && vy>=0 && vy<m && mat[vx][vy]==1){
            neig.push_back({vx, vy});
        }
    }

    return neig;
}

int main() {
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }

    // Multi source BFS
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==2){
                q.push({i, j});
                dis[i][j] = 0;
            }
            else dis[i][j] = 1e9;
        }
    }

    while(!q.empty()){
        pair<int , int> u = q.front(); q.pop();

        for(auto v : neighbour(u)){
            int vx = v.first, vy = v.second;
            if(dis[vx][vy]==1e9){
                dis[vx][vy] = dis[u.first][u.second]+1;
                mat[vx][vy]=2;
                q.push({vx, vy});
            }
        }
    }

    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==1){
                ans = -1; break;
            }
            if(mat[i][j]==2){
                ans = max(ans, dis[i][j]);
            }
        }
    }

    cout<<ans;

    return 0;
}

