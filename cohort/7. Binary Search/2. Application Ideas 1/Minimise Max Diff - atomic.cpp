#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> arr;

bool check(int mid,int k){
    int total=0;
    for(int i=1; i<arr.size(); i++){
        int diff=arr[i]-arr[i-1];
        int count=((diff+mid-1)/mid)-1;
        total+=count;
    }
    return total<=k;
}

signed main(){
    int t; cin>>t; while(t--){
        int n,k; cin>>n>>k;
        arr.resize(n);
        int r=0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(i>0){
                r=max(r,(arr[i]-arr[i-1]));
            }
        }
        int l=1;
        int ans=r;
        while(l<=r){
            int mid=(l+(r-l)/2);
            if(check(mid,k)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}