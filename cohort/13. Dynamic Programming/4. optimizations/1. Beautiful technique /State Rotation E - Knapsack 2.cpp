#define _GLIBCXX_FILESYSTEM
#include<bits/stdc++.h>
#define mod 1000000007
#define read(n) ll n;cin>>n
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define initialize(n,A) int n;cin>>n;vector<int> A(n);for(int i=0;i<n;i++) cin>>A[i]
#define inf 1e9
#define INF 1e18
#define fi first
#define se second
#define endl '\n'
#define full(A) A.begin(),A.end()
#define rfull(A) A.rbegin(),A.rend()
#define  pb push_back
#define vi vector<int>
using namespace std;
using ll = long long;
using pii= pair<int,int>;
int inv(int i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b);}
int n,W;
int wt[101],val[101];
ll dp[101][100100];

ll rec(int level, int profit){//min weight I need to make profit from level to n-1
    //pruning
    if(profit<0)return INF;

    //basecase
    if(level==n){
        if(profit==0)return 0;
        else return INF;
    }

    //cache check
    if(dp[level][profit]!=-1)return dp[level][profit];

    //compute
    ll ans=INF;
    ans=min(ans,rec(level+1,profit-val[level])+wt[level]);
    ans=min(ans,rec(level+1,profit));

    //save and return
    return dp[level][profit]=ans;

}

    
void solve(){
    cin>>n>>W;
    ff(i,0,n-1){
        cin>>wt[i]>>val[i];
    }
    memset(dp,-1,sizeof(dp));

    fr(p,100000,0){
        if(rec(0,p)<=W){
            cout<<p<<endl;break;
        }
    }


}
    
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t=1; cin>>t; while(t--)
    solve();
    return 0;
}