#include <bits/stdc++.h>
using namespace std;

int queen[15];
int ans=0;
int n;
int dx[]={-1,-2,-2,-1};
int dy[]={-2,-1,1,2};

bool check(int r,int c){
    for(int pr=0; pr<r; pr++){
        int pc=queen[pr];
        if(pc==c||abs(pc-c)==abs(pr-r))
            return false;
    }

    for(int i=0; i<4; i++){
        int pr=r+dx[i];
        int pc=c+dy[i];

        if(pr>=0&&pr<n&&pc>=0&&queen[pr]==pc)
            return false;
    }
    return true;
}

void solve(int r){
    if(r==n){
        ans++;
        return;
    }

    for(int c=0; c<n; c++){
        if(check(r,c)){
            queen[r]=c;
            solve(r+1);
            queen[r]=0;
        }
    }
}

int main(){
    cin>>n;
    solve(0);
    cout<<ans;
    return 0;
}