#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> A;

bool check(int mid){
    int zeros=0;
    for(int i=0; i<n; i++){
        if(A[i]==0) zeros++;
        if(i-mid>=0)    if(A[i-mid]==0) zeros--;
        if(i>=(mid-1))  if(zeros<=k) return 1;
    }
    return 0;
}

int main(){
    int t; cin>>t; while(t--){
        cin>>n>>k;
        A.resize(n);
        for(int i=0; i<n; i++) cin>>A[i];
        int l=0,r=n,ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
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