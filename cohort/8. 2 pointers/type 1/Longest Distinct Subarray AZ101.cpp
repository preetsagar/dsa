#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t; cin>>t; while(t--){
        int n;  cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        int tail=0,head=-1;
        int ans=0;
        map<int,int> mp;
        while(tail<n){
            while(head+1<n&&mp[arr[head+1]]==0){
                head++;
                mp[arr[head]]++;
            }
            ans=max(ans,head-tail+1);
            if(tail>head){
                tail++;
                head=tail-1;
            }
            else{
                mp[arr[tail]]--;
                tail++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}