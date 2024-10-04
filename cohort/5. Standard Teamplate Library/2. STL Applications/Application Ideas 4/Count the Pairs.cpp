#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--){
        int n,x; cin>>n>>x;
        vector<int> arr(n),tmp;
        long long ans=0;
        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr.begin(),arr.end());

        // method 1 using upper_bound
        for(int i=0; i<n; i++){
            if(!tmp.empty()){
                auto it=upper_bound(tmp.begin(),tmp.end(),(x-arr[i]));
                ans+=(it-tmp.begin());
            }
            tmp.push_back(arr[i]);
        }
        cout<<ans*2<<"\n";

        // method 2 using 2 pointers
        int l=0,r=n-1;
        while(l<r){
            if(arr[l]+arr[r]>x)   r--;
            else    { ans+=(r-l);l++; }
        }
        cout<<2*ans<<"\n";
    }
    return 0;
}