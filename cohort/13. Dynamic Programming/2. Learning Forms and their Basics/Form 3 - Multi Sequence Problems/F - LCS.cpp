#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[3100][3100];

int rec(int i, int j){
    // pruning
    // base case
    if(i==s1.size() || j==s2.size()) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    // transaction
    int ans = -1e9;
    if(s1[i]==s2[j]) ans = max(ans, rec(i+1, j+1) + 1);
    ans = max(ans, rec(i+1, j));
    ans = max(ans, rec(i, j+1));

    return dp[i][j] = ans;

}

void generate(int i, int j){
    if(i==s1.size() || j==s2.size()) return;
    
    int b = rec(i+1, j);
    int c = rec(i, j+1);
    
    if(s1[i]==s2[j]){
        cout<<s1[i];
        generate(i+1, j+1);
    }
    else if(b > c){
        generate(i+1, j);
    }
    else{
        generate(i, j+1);
    }
}

int main() {
    cin>>s1>>s2;
    memset(dp, -1, sizeof(dp));
    rec(0, 0);
    generate(0, 0);
    
    return 0;
}