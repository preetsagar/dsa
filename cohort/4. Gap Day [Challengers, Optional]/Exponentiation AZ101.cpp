#include <bits/stdc++.h>
using namespace std;

int binpow(int a,int b,int mod){
    if(b==0) return 1;
    if(b%2==1) return (a*1ll*binpow(a,b-1,mod))%mod;
    else{
        int t=binpow(a,b/2,mod);
        return (t*1ll*t)%mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t; while(t--){
        int a,b,c,p;
        cin>>a>>b>>c>>p;
        if(b==0&&c!=0) {
            cout<<'1'<<'\n';
        }
        else if(a%p==0||a==0) {
            cout<<"0\n";
        }
        else{
            int t=binpow(b,c,p-1);
            t=binpow(a,t,p);
            cout<<t<<"\n";
        }
    }
    return 0;
}