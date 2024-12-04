#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;
vector<int> A;

bool check(int mid,int k){
    int tail=0,head=-1,sum=0,count=0;
    while(tail<n){
        while(head+1<n&&sum+A[head+1]<=mid){
            head++;
            sum+=A[head];
        }
        count+=(head-tail+1);
        if(tail>head){
            tail++;
            head=tail-1;
        }
        else{
            sum-=A[tail];
            tail++;
        }
    }
    return count>=k;
}

signed main(){
    int t; cin>>t; while(t--){
        cin>>n;
        A.resize(n);
        int sum=0;
        for(int i=0; i<n; i++){
            cin>>A[i];
            sum+=A[i];
        }
        int total=(n*(n+1))/2;
        int k=(total+1)/2;

        int l=0,r=sum,ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
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