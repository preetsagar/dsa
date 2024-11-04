#include <bits/stdc++.h>
using namespace std;

int check(int mid,vector<int>& arr){
    return arr[mid]<arr[0];
}

int main(){
    int t; cin>>t;while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        int l=0,r=n-1;
        int ans=0;
        while(l<=r){
            int mid=(l+(r-l)/2);
            if(check(mid,arr)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}