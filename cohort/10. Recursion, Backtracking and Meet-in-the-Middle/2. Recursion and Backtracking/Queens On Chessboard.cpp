#include <bits/stdc++.h>
using namespace std;

int queen[8];
char board[8][8];
int ans=0;
int n;

bool check(int r,int c){
    for(int pr=0; pr<r; pr++){
        int pc=queen[pr];
        if(pc==c||abs(pc-c)==abs(pr-r))
            return false;
    }
    return true;
}

void solve(int r){
    if(r==8){
        ans++;
        return;
    }

    for(int c=0; c<8; c++){
        if(board[r][c]!='*'&&check(r,c)){
            queen[r]=c;
            solve(r+1);
            queen[r]=0;
        }
    }
}

int main(){
    n=8;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }
    solve(0);
    cout<<ans;
    return 0;
}