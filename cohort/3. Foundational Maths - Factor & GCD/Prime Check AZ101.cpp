#include <bits/stdc++.h>
using namespace std;

string prime(int n){
    if(n==1) return "NO";
    if(n==2) return "YES";

    for(int i=2; i*i<=n; i++){
        if(n%i==0) return "NO";
    }
    return "YES";
}

int main() {
    int t;cin>>t;while(t--){
        int n;cin>>n;
        cout<<prime(n)<<"\n";
    }
    return 0;
}