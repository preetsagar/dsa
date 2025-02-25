#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<char>> arr;
vector<vector<int>> vis;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void DFS(int i,int j){
    vis[i][j]=1;
    for(int it=0; it<4; it++){
        int x=i+dx[it];
        int y=j+dy[it];
        if(x>=0&&x<n&&y>=0&&y<m&&vis[x][y]==0&&arr[x][y]=='.'){
            DFS(x,y);
        }
    }
}

int main(){
    cin>>n>>m;
    arr.resize(n,vector<char>(m));
    vis.resize(n,vector<int>(m,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    int count=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j]&&arr[i][j]=='.'){
                count++;
                DFS(i,j);
            }
        }
    }
    cout<<count;

    return 0;
}