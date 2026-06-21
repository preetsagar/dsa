#include<bits/stdc++.h>
using namespace std;

#define int long long

int dp[5100];

string str;
int n;

int solve(int i){
  if(i<=0) return 1;
  
  if(dp[i]!=-1) return dp[i];
  
  int ans = 0;
  if(str[i]!='0') ans += solve(i-1);
  if(((str[i-1]-'0')*10 + (str[i]-'0'))<=26 && ((str[i-1]-'0')*10 + (str[i]-'0'))>=10){
      ans += solve(i-2);
  }
  
  return dp[i] = ans;
}

signed main(){
  while(cin>>str){
      memset(dp, -1, sizeof(dp));
      n = str.size();
      if(str=="0") break;
      
      if(solve(n-1)!=0) cout<<solve(n-1)<<"\n";
  }
  return 0;
}