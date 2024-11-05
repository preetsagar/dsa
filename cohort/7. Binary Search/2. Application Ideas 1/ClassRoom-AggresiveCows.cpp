#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k;
vector<int> A;

int check(int mid){
    int last_placed=INT_MIN;
    int total_placed=0;
    for(int i : A){
        if(i-last_placed>=mid){
            total_placed++;
            last_placed=i;
        }
    }
    return total_placed>=k;
}

signed main(){
    int t; cin>>t; while(t--){
        cin>>n>>k;
        A.resize(n);
        for(int i=0; i<n; i++) cin>>A[i];
        sort(A.begin(),A.end());

        int  l=0,r=1e9,ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
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