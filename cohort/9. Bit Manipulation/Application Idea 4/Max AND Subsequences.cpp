#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t; while(t--){
        int n,x; cin>>n>>x;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        long long ans=0;
        for(int i=29; i>=0; i--){
            vector<int> tmp;
            int one=0,zero=0;
            for(int j : arr){
                if(1&(j>>i)){
                    tmp.push_back(j);
                }
            }
            if(tmp.size()>=x){
                ans+=(1LL<<i);
                arr=tmp;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}