#include <bits/stdc++.h>
using namespace std;

int n,m; 
vector<vector<int>> mat;
vector<vector<int>> mdist;
queue<pair<int, int>> q;

void bfs(){
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && nx<n and ny>=0 && ny<m && mat[nx][ny]==1 && mdist[nx][ny]==1e9){
                mdist[nx][ny] = mdist[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin>>n>>m;
    mdist.assign(n, vector<int>(m, 1e9));
    mat.assign(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
            if(mat[i][j]==2){
                q.push({i, j});
                mdist[i][j]=0;
            }
        }
    }
    bfs();

    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==1){
                ans = max(ans, mdist[i][j]);
            }
        }
    }
    if(ans>=1e9){
        cout<<"-1";
    }else{
        cout<<ans;
    }
    return 0;
}