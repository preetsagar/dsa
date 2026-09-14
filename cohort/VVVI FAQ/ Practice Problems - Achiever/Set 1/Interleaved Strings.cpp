#include <bits/stdc++.h>
using namespace std;

string x,y,z;

int dp[1100][1100];

int solve(int i, int j){
    int k=i+j;

    if(k==z.size()){
        return i==x.size() && j==y.size();
    }

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 0;
    if(i<x.size() && x[i]==z[k]){
        ans |= solve(i+1, j);
    }
    if(j<y.size() && y[j]==z[k]){
        ans |= solve(i, j+1);
    }

    return dp[i][j]=ans;
}

int main() {
    
    cin>>x>>y>>z;
    memset(dp, -1, sizeof(dp));
    if(solve(0, 0)) cout<<"Yes";
    else cout<<"No";

    return 0;
}