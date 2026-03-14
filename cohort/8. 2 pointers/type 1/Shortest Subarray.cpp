#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,k;
vector<int> arr;

int solve(){
    int tail=0, head=-1;
    int ans, overallAns=n;
    map<int, int> mp;
    while(tail <n){
        while(head+1 < n && mp.size()<k){
            head++;
            mp[arr[head]]++;
        }
        if(mp.size()==k){
            ans = (head-tail+1);
            overallAns = min(overallAns, ans);
        }
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
        map<int, int> mp;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        k = mp.size();
        cout<<solve()<<"\n";
    }
    return 0;
}