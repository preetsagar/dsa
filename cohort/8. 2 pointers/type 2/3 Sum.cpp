#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t; cin>>t; while(t--){
        int n,sum; cin>>n>>sum;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        int ans=LLONG_MAX;

        for(int i=1; i<n-1; i++){
            int l=0,r=n-1;
            while(l<i&&r>i){
                int t=arr[l]+arr[i]+arr[r];
                if(t==sum){
                    ans=0;break;
                }
                else if(t>=sum){
                    ans=min(ans,abs(t-sum));
                    r--;
                }
                else{
                    ans=min(ans,abs(t-sum));
                    l++;
                }
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}