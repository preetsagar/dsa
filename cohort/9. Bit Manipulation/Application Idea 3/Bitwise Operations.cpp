#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        int bits[31]={0};
        for(int i=0; i<31; i++){
            for(int j=0; j<n; j++){
                if(1&(arr[j]>>i)){
                    bits[i]++;
                }
            }
        }

        long long ans=0;
        for(int j=0; j<n; j++){
            int num=0;
            for(int i=0; i<31; i++){
                if(bits[i]>0){
                    num|=(1<<i);
                    bits[i]--;
                }
            }
            ans+=1LL*num*num;
        }

        cout<<ans<<"\n";
    }
    return 0;
}