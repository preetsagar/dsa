#include <bits/stdc++.h>
using namespace std;

int tc, n, m, k;
int A[1000100], B[1000100];

const int INF = 1e9;

int dp[2][1000100];

// (level, j)
//     (level-1, j) + A[level]
//     (level-k, j-1) + B[level] + B[level-k]

struct monotonic_deque{
    deque<int> dq;

    void insert(int x){
        while(!dq.empty() && dq.back()>x) dq.pop_back();
        dq.push_back(x);
    }

    void remove(int x){
        if(!dq.empty() && dq.front()==x){
            dq.pop_front();
        }
    }

    int getMin(){
        return dq.empty() ? 0 : dq.front();
    }
};

int main() {
    cin>>tc; while(tc--){
        cin>>n>>m>>k;
        for(int i=0; i<n; i++) cin>>A[i];
        for(int i=0; i<n; i++) cin>>B[i];

        int ans = INF;
        for(int j=0; j<=m; j++){
            monotonic_deque dq;
            for(int i=0; i<n; i++){
                if(i==0) {
                    if(j==0) dp[j&1][i] = 0;
                    else dp[j&1][i] = INF;
                    continue;
                }

                // BUS
                dp[j&1][i] = INF;
                dp[j&1][i] = min(dp[j&1][i], dp[j&1][i-1] + A[i-1]);

                // FLIGHT
                if(j>0){
                    dq.insert(dp[(j-1)&1][i-1] + B[i-1]);
                    if(i-k-1 >= 0) dq.remove(dp[(j-1)&1][i-k-1] + B[i-k-1]);
                    dp[j&1][i] = min(dp[j&1][i], dq.getMin() + B[i]);
                }
            }
            ans = min(ans, dp[j&1][n-1]);
        }

        cout<<ans<<'\n';
    }
    return 0;
}