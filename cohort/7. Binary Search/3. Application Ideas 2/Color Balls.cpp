#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,k;
map<int,int> m;

bool check(int mid){
    int x=0,ans=0;
    for(auto i:m){
        x+=min(i.second,mid);
    }
    return x>=mid*k;
}

signed main(){
    int t; cin>>t; while(t--){
        cin>>n>>k;
        m.clear();
        for(int i=0; i<n; i++){
            int t; cin>>t; m[t]++;
        }

        int l=0,r=1e5,ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            // cout<<mid<<" ";
            if(check(mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

