#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<vector<int>> grid, vis;
int ccSize=0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int ui, int uj){
    vis[ui][uj] = 1;
    ccSize++;

    for(int i=0; i<4; i++){
        int vi = ui + dx[i];
        int vj = uj + dy[i];

        if(vi>=0 && vi<n && vj>=0 && vj<10 && grid[ui][uj]==grid[vi][vj] && vis[vi][vj]==0){
            dfs(vi, vj);
        }
    }
}

void erase(int ui, int uj){
    int col = grid[ui][uj];
    grid[ui][uj] = 0;

    for(int i=0; i<4; i++){
        int vi = ui + dx[i];
        int vj = uj + dy[i];

        if(vi>=0 && vi<n && vj>=0 && vj<10 && col==grid[vi][vj]){
            erase(vi, vj);
        }
    }
}

void resetVis(){
    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            vis[i][j] = 0;
        }
    }
}

void gravity(){
    vector<vector<int>> temp(n, vector<int>(10, 0));
    for(int j=0; j<10; j++){
        int i1=n-1, i2=n-1;
        while(i1>=0 && i2>=0){
            if(grid[i1][j] != 0){
                temp[i2][j] = grid[i1][j];
                i2--;
            }
            i1--;
        }
    }
    grid = temp;
}

void printGrid(){
    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
}

int main() {
    cin>>n>>k;
    grid.resize(n, vector<int>(10));
    vis.resize(n,vector<int>(10,0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            char x; cin>>x;
            grid[i][j] = x - '0';
        }
    }

    bool found;
    do {
        found = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<10; j++){
                ccSize=0;
                if(grid[i][j]!=0 && vis[i][j]==0){
                    dfs(i, j);
                    
                    if(ccSize>=k){
                        erase(i, j);
                        found = true;
                    }
                }
            }
        }
        if(found){
            gravity();
            resetVis();
        }
    } while(found);
    
    printGrid();

    return 0;
}