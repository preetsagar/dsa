#include <bits/stdc++.h>
using namespace std;

int divisors(int n){
    int count=0;
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            count++;
            if(i*i!=n) count++;
        }
    }
    return count;
}

int main() {
    int t;cin>>t;while(t--){
        int n;cin>>n;
        cout<<divisors(n)<<"\n";
    }
    return 0;
}