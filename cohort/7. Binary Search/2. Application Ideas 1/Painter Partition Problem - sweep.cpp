#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> arr;

bool check(int mid,int k){
    int lastPainterTimeRemaining=0;
    int noOfPainter=0;
    for(int i=0; i<arr.size(); i++){
        if(lastPainterTimeRemaining<arr[i]){
            noOfPainter++;
            lastPainterTimeRemaining=mid;
            if(noOfPainter>k||lastPainterTimeRemaining<arr[i]) return 0;
            lastPainterTimeRemaining-=arr[i];
        }
        else lastPainterTimeRemaining-=arr[i];
    }
    return 1;
}

signed main(){
    int t; cin>>t; while(t--){
        int n,k; cin>>n>>k;
        arr.resize(n);
        int total=0;
        for(int i=0; i<n; i++){ cin>>arr[i]; total+=arr[i]; }
        int l=0,r=total;
        int ans=-1;
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