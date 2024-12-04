#include <bits/stdc++.h>
using namespace std;

vector<int> freq(1000100,0);

int main(){
    int t; cin>>t; while(t--){
        int n,k; cin>>n>>k;
        vector<int>arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        int tail=0,head=-1,distElement=0;
        long long ans=0;
        while(tail<n){
            while(head+1<n&&(distElement<k||freq[arr[head+1]]>0)){
                head++;
                if(freq[arr[head]]==0) distElement++;
                freq[arr[head]]++;
            }
            ans+=(head-tail+1);
            if(tail>head){
                tail++;
                head=tail-1;
            }
            else{
                freq[arr[tail]]--;
                if(freq[arr[tail]]==0) distElement--;
                tail++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}