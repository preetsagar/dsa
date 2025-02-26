#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

int n,m;
vector<vector<int>> mat,vis;
using state=pair<int,int>;

bool isValid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&mat[x][y]==0) return true;
    return false;
}

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
vector<state> neighbour(state u){
    vector<state> arr;
    for(int i=0; i<4; i++){
        int x=u.F+dx[i];
        int y=u.S+dy[i];

        if(isValid(x,y)){
            arr.push_back({x,y});
        }
    }
    return arr;
}

int BFS(state st){
    queue<state> q;
    q.push(st);
    vis[st.F][st.S]=1;
    int count=1;

    while(!q.empty()){
        state u=q.front(); q.pop();

        for(state v : neighbour(u)){
            if(!vis[v.F][v.S]){
                vis[v.F][v.S]=1;
                q.push(v);
                count++;
            }
        }
    }
    return count;
}

void color(state st,int c){
    queue<state> q;
    q.push(st);
    mat[st.F][st.S]=c;

    while(!q.empty()){
        state u=q.front(); q.pop();

        for(state v : neighbour(u)){
            if(!mat[v.F][v.S]){
                mat[v.F][v.S]=c;
                q.push(v);
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        mat.assign(n,vector<int>(m));
        vis.assign(n,vector<int>(m,0));

        // take input
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>mat[i][j];
            }
        }

        // calculate
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    int count=BFS({i,j});
                    if(count>1){
                        color({i,j},count);
                    }
                }
            }
        }

        // print
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }

    }
    return 0;
}