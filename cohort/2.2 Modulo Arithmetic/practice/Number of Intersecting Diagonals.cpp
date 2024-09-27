#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
#define int long long

int binpow(int a,int b){
    if(b==0) return 1;
    if(b%2==1) return (a*binpow(a,b-1))%mod;
    else{
        int t=binpow(a,b/2);
        return (t*t)%mod;
    }
}

int inverse(int a,int b){
    return binpow(a,b-2);
}

signed main() {
    int t; cin>>t;
    int b=inverse(24,mod);
    while(t--){
        long long n; cin>>n;
        int t=n;
        t=(t*(n-1))%mod;
        t=(t*(n-2))%mod;
        t=(t*(n-3))%mod;

        // nC4
        cout<<(t*b)%mod<<"\n";
    }
    return 0;
}