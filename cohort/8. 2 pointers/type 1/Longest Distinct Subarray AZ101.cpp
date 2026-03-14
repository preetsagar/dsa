#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> arr;

int solve(){
    int tail=0, head=-1;
    int ans=0, overallAns=0;
    map<int, int> mp;
    while(tail <n){
        while(head+1 < n && mp.find(arr[head+1])==mp.end()){
            head++;
            mp[arr[head]]++;
        }
        ans = (head-tail+1);
        overallAns = max(overallAns, ans);
        if(tail > head){
            tail++;
            head = tail-1;
        }else{
            mp[arr[tail]]--;
            if(mp[arr[tail]]==0) mp.erase(arr[tail]);
            tail++;
        }
    }
    return overallAns;
}

signed main() {
    int t; cin>>t; while(t--){
        cin>>n;
        arr.resize(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        cout<<solve()<<"\n";
    }
    return 0;
}