#include <bits/stdc++.h>
using namespace std;

int n,m; 
vector<string> mat;
vector<vector<int>> mdist, dist;
queue<pair<int, int>> q;

void bfs(vector<vector<int>>& mdist){
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && nx<n and ny>=0 && ny<m && mat[nx][ny]=='.' && mdist[nx][ny]==1e9){
                mdist[nx][ny] = mdist[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin>>n>>m;
    dist.assign(n, vector<int>(m, 1e9));
    mdist.assign(n, vector<int>(m, 1e9));
    for(int i=0; i<n; i++){
        string str; cin>>str;
        mat.push_back(str);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]=='M'){
                q.push({i, j});
                mdist[i][j] = 0;
            }
        }
    }
    bfs(mdist);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]=='A'){
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    bfs(dist);
    
    int ans=1e9;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 || i==n-1 || j==0 ||j==m-1){
                if(dist[i][j] < mdist[i][j]){
                    ans = min(ans, dist[i][j]);
                }
            }
        }
    }
    if(ans==1e9){
        cout<<"NO\n";
    }else{
        cout<<"YES\n"<<ans;
    }


    return 0;
}