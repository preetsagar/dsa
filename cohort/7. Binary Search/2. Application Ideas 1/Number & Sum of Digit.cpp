#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,s;

bool check(int mid){
    int x = mid;
    int sum=0;
    while(mid){
        sum += (mid%10);
        mid /= 10;
    }
    return (x-sum)>=s;
}

signed main() {
    int t; cin>>t; while(t--){
        cin>>n>>s;
        int l = 1;
        int r = n;
        int ans = n+1;
        while(l<=r){
            int mid = (l+(r-l)/2);
            if(check(mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        cout<<n+1-ans<<"\n";
    }
    return 0;
}
