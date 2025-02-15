#include <bits/stdc++.h>
using namespace std;

int n;
int ans=0;
int board[3][3];
int dx[]={-2,-2,-1,-1,+1,+1,+2,+2};
int dy[]={-1,+1,+2,-2,+2,-2,+1,-1};

/* starting at (r, c), tell me the no of unlock patterns connecting exactly (n-len) cells.*/
void solve(int r,int c,int len){
    if(len==n){
        ans++;
        return;
    }

    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0&&j==0) continue;
            int x=r+i;
            int y=c+j;

            if(x>=0&&x<3&&y>=0&&y<3&&board[x][y]==0){
                board[x][y]=1;
                solve(x,y,len+1);
                board[x][y]=0;
            }
            if(x>=0&&x<3&&y>=0&&y<3&&board[x][y]==1){
                x+=i;
                y+=j;
                if(x>=0&&x<3&&y>=0&&y<3&&board[x][y]==0){
                    board[x][y]=1;
                    solve(x,y,len+1);
                    board[x][y]=0;
                }
            }
        }
    }

    for(int i=0; i<8; i++){
        int x=r+dx[i];
        int y=c+dy[i];

        if(x>=0&&x<3&&y>=0&&y<3&&board[x][y]==0){
            board[x][y]=1;
            solve(x,y,len+1);
            board[x][y]=0;
        }
    }
}



int main(){
    cin>>n;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j]=1;
            solve(i,j,1);
            board[i][j]=0;
        }
    }
    cout<<ans;
    return 0;
}