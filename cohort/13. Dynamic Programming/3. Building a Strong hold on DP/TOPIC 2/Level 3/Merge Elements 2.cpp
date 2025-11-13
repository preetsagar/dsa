#include <bits/stdc++.h>
using namespace std;

int n,X,Y,Z;
int arr[60];
int dp[60][60][60];
int done[60][60];

int rec(int l, int r, int val){
    if(l==r){
        if(val==arr[l]) return 0;
        return 1e9;
    }

    if(done[l][r]!=-1) return dp[l][r][val];

    for(int i=0; i<50; i++) dp[l][r][i] = 1e9;

    for(int mid=l; mid<r; mid++){
        for(int lv=0; lv<50; lv++){
            for(int rv=0; rv<50; rv++){
                dp[l][r][(lv*X + rv*Y + Z)%50] = min(dp[l][r][(lv*X + rv*Y + Z)%50], 
                                                    rec(l, mid, lv) + rec(mid+1, r, rv) + lv*rv);
            }
        }
    }

    done[l][r] = 1;
    return dp[l][r][val];
}

int main() {
    cin>>n>>X>>Y>>Z;
    for(int i=0; i<n; i++) cin>>arr[i];
    int ans = 1e9;
    memset(done, -1, sizeof(done));
    for(int i=0; i<50; i++){
        ans = min(ans, rec(0, n-1, i));
    }
    cout<<ans;
    return 0;
}