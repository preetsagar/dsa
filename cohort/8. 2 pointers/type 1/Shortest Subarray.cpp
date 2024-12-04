#include <bits/stdc++.h>
using namespace std;

int freq[100010]={0};

int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        set<int> st;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            st.insert(arr[i]);
        }
        int totalDistEle=st.size();

        int tail=0,head=-1,distEle=0;
        int ans=n;
        while(tail<n){
            while(head+1<n&&distEle<totalDistEle){
                head++;
                freq[arr[head]]++;
                if(freq[arr[head]]==1) distEle++;
            }
            if(distEle==totalDistEle){
                ans=min(ans,head-tail+1);
            }
            if(tail>head){
                tail++;
                head=tail-1;
            }
            else{
                freq[arr[tail]]--;
                if(freq[arr[tail]]==0) distEle--;
                tail++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}