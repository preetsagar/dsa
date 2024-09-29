#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod=1e9+7;

signed main() {
    int t;cin>>t;while(t--){
        int p=1;
        int n; cin>>n; while(n--){
            int t; cin>>t;
            p=(p*t)%mod;
        }
        cout<<p<<"\n";
    }
    return 0;
}