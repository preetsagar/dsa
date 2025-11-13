#include <bits/stdc++.h>
using namespace std;

int t, n,m, k;
int MOD = 1e9+7;

int rec(int level, int k){
    if(level==n){
        if(k==0) return 1;
        return 0;
    }

    int ans = 0;
    ans += (ans%MOD + rec(level+1, k)%MOD)%MOD;
    ans += (((ans%MOD + rec(level+1, k)%MOD)%MOD)*(m-1)%MOD)%MOD;

    return ans;
}

int main() {
    cin>>t; while(t--){
        cin>>n>>m>>k;
        cout<<(rec(1, k)*(m))%MOD<<'\n';
    }
    return 0;
}