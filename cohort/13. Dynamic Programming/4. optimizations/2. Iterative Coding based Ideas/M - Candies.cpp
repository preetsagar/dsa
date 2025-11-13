#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int M   = 1e9+7;   // 998244353;



// we can optimize by building prefix sum in the dp array, which can be only done in iterative style


int n,k;
int a[101];


void sigmale(){
    cin>>n>>k;
    for(int i=0; i<n; i++)cin>>a[i];
    
    vector<vector<int>> dp(n+1,vector<int> (k+1,0));
    
    for(int level=n; level>=0; level--){
        for(int sum_left=0; sum_left<=k; sum_left++){
                    // bc
                    if(level==n){
                          if(sum_left==0)dp[level][sum_left]=1;
                          else dp[level][sum_left]=0;
                    }
                    else{
                        dp[level][sum_left] = dp[level+1][sum_left];
                        if(sum_left-a[level]-1>=0)dp[level][sum_left] -= dp[level+1][sum_left-a[level]-1];
                    }
        }


        // before going to the next row, build prefix sum of the row
       for(int sum_left=0; sum_left<=k; sum_left++){
                        if(sum_left)dp[level][sum_left]=(dp[level][sum_left]+dp[level][sum_left-1])%M;
        }  


    }
     
      int ans;
      if(k==0)ans=dp[0][k];
      else ans=dp[0][k]-dp[0][k-1];
      cout << ((ans%M)+M)%M << endl;
}


signed main(){    
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);  
    //int t; cin>>t; while(t--)
        sigmale();
}
