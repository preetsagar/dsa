#include <bits/stdc++.h>
using namespace std;

int check(int mid,vector<int>& arr){
    if(mid==arr.size()-1) return 1;
    return arr[mid]>arr[mid+1];
}

int find(vector<int>& arr,int l,int r,int x){
    int ans=r+1;
    while(l<=r){
        int mid=(l+(r-l)/2);
        if(arr[mid]<=x){
            if(arr[mid]==x) return mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

signed main(){
    int t; cin>>t;while(t--){
        int n,q; cin>>n>>q;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        // find bitonic index
        int l=0,r=n-1;
        int idx=n-1;
        while(l<=r){
            int mid=(l+(r-l)/2);
            if(check(mid,arr)){
                idx=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        while(q--){
            int x; cin>>x;
            int lo,hi;

            lo=0;
            hi=idx;
            while(lo<=hi){
                int mid=(lo+hi)/2;
                if(arr[mid]==x){
                    cout<<mid+1<<" ";
                    break;
                }
                else if(arr[mid]>x){
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }


            lo=idx+1;
            hi=n-1;
            while(lo<=hi){
                int mid=(lo+hi)/2;
                if(arr[mid]==x){
                    cout<<mid+1;
                    break;
                }
                else if(arr[mid]>x){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
            cout<<'\n';
        }
    }
    return 0;
}