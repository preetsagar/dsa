#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> A,B;

bool check(int mid,int k){
    int count=0;
    for(int i : A){
        count+=(upper_bound(B.begin(),B.end(),mid-i)-B.begin());
    }
    return count>=k;
}


signed main(){
    int t; cin>>t; while(t--){
        int n,m,k; cin>>n>>m>>k;
        A.resize(n);
        B.resize(m);
        for(int i=0; i<n; i++) cin>>A[i];
        for(int i=0; i<m; i++) cin>>B[i];
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());

        if(n>m){
            swap(n,m);
            swap(A,B);
        }

        int l=0,r=2e4,ans=-1;
        while(l<=r){
            int mid=((l+r)/2);
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