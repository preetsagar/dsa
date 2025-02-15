#include <bits/stdc++.h>
using namespace std;

string s;
int board[7][7];
int ans=0,n=7;

int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,-1,+1};
string dir="DULR";

void solve(int level,int i,int j){

    if(level==48){
        if(i==6&&j==0) ans++;
        return;
    }

    // pruning of the year
    if(((i+1==n||(board[i-1][j]&&board[i+1][j]))&&j-1>=0&&j+1<n&&!board[i][j-1]&&!board[i][j+1])||
        ((j+1==n||(board[i][j-1]&&board[i][j+1]))&&i-1>=0&&i+1<n&&!board[i-1][j]&&!board[i+1][j])||
        ((i==0||(board[i+1][j]&&board[i-1][j]))&&j-1>=0&&j+1<n&&!board[i][j-1]&&!board[i][j+1])||
        ((j==0||(board[i][j+1]&&board[i][j-1]))&&i-1>=0&&i+1<n&&!board[i-1][j]&&!board[i+1][j]))
        return;

    board[i][j]=1;
    if(s[level]=='?'){
        for(int k=0; k<4; k++){
            int newx=i+dx[k];
            int newy=j+dy[k];

            if(newx>=0&&newx<7&&newy>=0&&newy<7&&board[newx][newy]==0){
                // s[level] = dir[k];
                solve(level+1,newx,newy);
                // s[level] = '?';
            }
        }
    }
    else{
        if(s[level]=='U'&&i-1>=0&&board[i-1][j]==0) solve(level+1,i-1,j);
        if(s[level]=='D'&&i+1<7&&board[i+1][j]==0) solve(level+1,i+1,j);
        if(s[level]=='L'&&j-1>=0&&board[i][j-1]==0) solve(level+1,i,j-1);
        if(s[level]=='R'&&j+1<7&&board[i][j+1]==0) solve(level+1,i,j+1);
    }
    board[i][j]=0;
}

int main(){
    cin>>s;
    solve(0,0,0);
    cout<<ans;
    return 0;
}