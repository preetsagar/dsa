#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main() {
    int t;cin>>t; while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(b>a) swap(a,b);
        if(c%(gcd(a,b))==0) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}