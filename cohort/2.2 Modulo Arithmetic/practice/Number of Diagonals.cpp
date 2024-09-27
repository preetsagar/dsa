#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int main() {
    int t; cin>>t; while(t--){
        long long n; cin>>n;
        cout<<(((n*(n-1)))/2-n)%mod<<"\n";
    }
    return 0;
}

// (n*(n-1))/2 - n