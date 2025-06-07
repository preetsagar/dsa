#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> mat, dis;
int dx[4] = {0, 0, 1,-1};
int dy[4] = {1,-1, 0, 0};
        //   R. L. D. U. 

void bfs01(int si, int sj){
    deque<pair<int, int>> dq;
    dq.push_front({si, sj});
    dis[si][sj] = 0;

    while(!dq.empty()){
        auto [x, y] = dq.front(); dq.pop_front();
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                int w = (mat[x][y]==k+1) ? 0 : 1;
                if(dis[nx][ny] > dis[x][y] + w){
                    dis[nx][ny] = dis[x][y] + w;
                    if(w == 0) dq.push_front({nx, ny});
                    else dq.push_back({nx, ny});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    mat.resize(n, vector<int>(m));
    dis.assign(n, vector<int>(m, 1e9));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    bfs01(0, 0);
    cout << dis[n-1][m-1] << "\n";
    return 0;
}