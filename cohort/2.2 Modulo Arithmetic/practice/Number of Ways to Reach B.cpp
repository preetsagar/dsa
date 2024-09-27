#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod=1e9+7;
vector<int> fact(200010,0);

void precompute_factorial(){
    fact[0]=fact[1]=1;
    for(int i=2; i<200010; i++){
        fact[i]=(i*fact[i-1])%mod;
    }
}

int binpow(int a,int b){
    if(b==0) return 1;
    if(b%2==1) return (a*binpow(a,b-1))%mod;
    else{
        int t=binpow(a,b/2);
        return (t*t)%mod;
    }
}

int inverse(int a,int p){
    return binpow(a,p-2);
}

void nCr(int n,int r){
    int num=fact[n];
    int den1=inverse(fact[r],mod);
    int den2=inverse(fact[n-r],mod);

    int ans=(num*den1)%mod;
    ans=(ans*den2)%mod;

    cout<<ans<<"\n";
}

signed main() {
    precompute_factorial();
    int t; cin>>t; while(t--){
        int n,m;
        cin>>n>>m;
        nCr((n+m),n);
    }
    return 0;
}