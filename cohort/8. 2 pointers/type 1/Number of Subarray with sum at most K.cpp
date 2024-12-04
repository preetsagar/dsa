#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t; while(t--){
        int n,k; cin>>n>>k;
        vector<int>arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        int tail=0,head=-1;
        long long ans=0,sum=0;;
        while(tail<n){
            while(head+1<n&&(arr[head+1]+sum)<=k){
                sum+=arr[head+1];
                head++;
            }
            ans+=(head-tail+1);
            if(tail>head){
                tail++;
                head=tail-1;
            }
            else{
                sum-=arr[tail];
                tail++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}