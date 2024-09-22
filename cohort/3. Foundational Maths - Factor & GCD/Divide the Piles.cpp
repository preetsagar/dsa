#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main() {
    int t;cin>>t;while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int a=0;
        for(int i=0; i<n; i++){
            a=gcd(a,arr[i]);
        }
        if(a<2) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}