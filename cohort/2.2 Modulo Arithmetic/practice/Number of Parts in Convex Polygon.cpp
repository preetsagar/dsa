#include <bits/stdc++.h>
using namespace std;

#define int long long
int mod=1e9+7;

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
    int t;cin>>t;while(t--){
        int n; cin>>n;

        // nc2 - n
        int t1=(n*(n-1))%mod;
        t1=(t1*inverse(2,mod))%mod;

        // nc4
        int t2=n;
        t2=(t2*(n-1))%mod;
        t2=(t2*(n-2))%mod;
        t2=(t2*(n-3))%mod;
        t2=(t2*inverse(24,mod))%mod;

        // nc2 + nc4 + 1 - n
        // cout<<n<<" "<<t1<<" "<<t2<<"\n";
        int ans=(t1+t2+1)%mod;
        ans=(ans-n)%mod;
        if(ans<0) ans=(ans+mod)%mod;
        cout<<ans<<"\n";

    }
    return 0;
}