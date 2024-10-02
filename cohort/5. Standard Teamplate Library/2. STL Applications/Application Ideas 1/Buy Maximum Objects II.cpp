#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q; cin>>n>>q;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i=0; i<n; i++){
        if(i>0) arr[i]+=arr[i-1];
    }
    while(q--){
        int x; cin>>x;
        auto it=upper_bound(arr.begin(),arr.end(),x);
        cout<<(it-arr.begin())<<"\n";
    }
    return 0;
}