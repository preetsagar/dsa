#include <bits/stdc++.h>
using namespace std;

int tc,n,m;
set<pair<int, pair<int, int>>> mat;
int dp[1100][1100];

void rec(int i, int j){
    if(i>=n || j>=m || j<0) return;
    
    if(dp[i][j]!=-1) return;
    
    dp[i][j] = 0;
    
    rec(i+1, j-1);
    rec(i+1, j);
    rec(i+1, j+1);
}

int main() {
    cin>>tc; while(tc--){
        cin>>n>>m;
        mat.clear();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int x; cin>>x;
                mat.insert({-x, {i, j}});
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) dp[i][j] = -1;
        }

        for(auto it:mat){
            int i = it.second.first;
            int j = it.second.second;
            if(dp[i][j]!=-1) continue;
            dp[i][j] = 1;
            rec(i+1, j-1);
            rec(i+1, j);
            rec(i+1, j+1);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<dp[i][j];
            }
            cout<<'\n';
        }
    }
    return 0;
}