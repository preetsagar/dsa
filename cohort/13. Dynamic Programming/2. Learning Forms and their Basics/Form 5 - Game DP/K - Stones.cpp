#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[110];
int dp[110000];

int rec(int x){
    if(x==0) return 0;
    
    if(dp[x]!=-1) return dp[x];
    
    int ans = 0;
    for(int i=0; i<n; i++){
        if(arr[i]<=x){
            if(rec(x-arr[i])==0){
                ans = 1;
            }
        }
    }
    return dp[x] = ans;
}

int main() {
    cin>>n>>k;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(rec(k)) cout<<"First";
    else cout<<"Second";
    
    return 0;
}