#include <bits/stdc++.h>
using namespace std;

#define int long long

int arr[200010];
int n,q;

signed main()
{
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        arr[i] ^= arr[i-1];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<(arr[r]^arr[l-1])<<'\n';
    }
    
    return 0;
}