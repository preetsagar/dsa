#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define MP make_pair

vector<vector<char>> mat;
vector<vector<int>>  col;
using state=pair<int,int>;
int n;
queue<state> q;
int area=0;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void DFS(state u,int color){
    q.push(u);
    col[u.F][u.S]=color;
    area++;
    for(int i=0; i<4; i++){
        int xx=u.F+dx[i];
        int yy=u.S+dy[i];
        if(xx<0||xx>=n||yy<0||yy>=n||col[xx][yy]||mat[xx][yy]=='.')  continue;
        DFS({xx,yy},color);
    }
}

int perimeter(state u){
    int count=0;
    for(int i=0; i<4; i++){
        int xx=u.F+dx[i];
        int yy=u.S+dy[i];
        if(xx<0||xx>=n||yy<0||yy>=n||mat[xx][yy]=='.')  count++;
    }
    return count;
}

int main(){
    cin>>n;
    mat.resize(n,vector<char>(n));
    col.resize(n,vector<int>(n,0));
    // input
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }

    int peri=0,final_peri=0,final_area=0;
    int color=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!col[i][j]&&mat[i][j]=='#'){
                area=0;
                DFS({i,j},color);
                color++;
                peri=0;
                while(!q.empty()){
                    peri+=perimeter(q.front());
                    q.pop();
                }
                if(area>final_area){
                    final_area=area;
                    final_peri=peri;
                }
                else if(area==final_area){
                    final_peri=min(final_peri,peri);
                }
            }
        }
    }

    cout<<final_area<<" "<<final_peri;


    return 0;
}