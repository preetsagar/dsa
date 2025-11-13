#include <bits/stdc++.h>
using namespace std;

int tc, n, k;
string str;
int dp[1100][1100][5];
int back[1100][1100][5];

// Paper[0] Rock[1] Sessior[2]
int wins(int levelV, int currS){
    if(str[levelV]=='P' && currS==2) return 1;
    if(str[levelV]=='R' && currS==0) return 1;
    if(str[levelV]=='S' && currS==1) return 1;
    return 0;
}

int rec(int level, int k, int last){
    if(k<0) return -1e9;
    if(level==n) return 0;

    if(dp[level][k][last]!=-1) return dp[level][k][last];

    int ans = -1e9;
    for(int move=0; move<3; move++){
        int score = wins(level, move) + rec(level+1, k-(last!=move), move);
        if(score > ans || score == ans && move < back[level][k][last]){
            ans = score;
            back[level][k][last] = move;
        }
    }

    return dp[level][k][last] = ans;
}

string generate(int level, int k, int last){
    if(level==n) return "";

    int ch = back[level][k][last];
    char c = (ch==0 ? 'P' : ch==1 ? 'R' : 'S');
    return c + generate(level+1, k-(last!=ch), ch);
}

int main() {
    cin>>tc; while(tc--){
        cin>>n>>k>>str;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=k; j++){
                for(int c=0; c<=3; c++){
                    dp[i][j][c] = -1;
                }
            }
        }
        
        string bestSeq;
        int bestScore=-1e9;
        for(int i=0; i<3; i++){
            int score = rec(0, k, i);
            string seq = generate(0, k, i);
            if(score > bestScore || (score==bestScore && seq < bestSeq)){
                bestScore = score;
                bestSeq = seq;
            }
        }
        cout<<bestScore<<'\n'<<bestSeq<<'\n';
    }
    return 0;
}