
#include <bits/stdc++.h>
using namespace std;

int dp[11000][110];

int EggDrop(int N, int K)
{
    if(N==0 || N==1) return N;
    if(K==1) return N;

    if(dp[N][K]!=-1) return dp[N][K];

    int ans = 1e9;
    int l=1; 
    int r=N;
    while(l<=r){
        int dropFloor = (l+r)/2;
        int eggBroke = 1 + EggDrop(dropFloor-1, K-1);
        int eggNotBroke = 1 + EggDrop(N-dropFloor, K);

        int temp = max(eggBroke, eggNotBroke);
        ans = min(ans, temp);

        if(eggBroke > eggNotBroke){
            r = dropFloor-1;
        }else{
            l = dropFloor+1;
        }
    }

    // int ans = 1e9;
    // for(int i=1; i<=N; i++){
    //     // assume worst where there is luck involved
    //     // max(break, did not break);
    //     // Best of worst
    //     int temp = 1 + max(EggDrop(i-1, K-1) , EggDrop(N-i, K));
    //     ans = min(ans, temp);
    // }

    return dp[N][K] = ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;

    memset(dp, -1, sizeof(dp));
    cout << EggDrop(N, K) << "\n";
}
