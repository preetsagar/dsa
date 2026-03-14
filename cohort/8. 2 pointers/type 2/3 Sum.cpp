#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,sum;
vector<int> arr;

int solve(){
    int ans = LONG_MAX;
    for(int j=0; j<n; j++){
        int i=0, k=n-1;
        while(i<j && j<k){
            ans = min(ans, abs(arr[i]+arr[j]+arr[k] - sum));
            if(arr[i]+arr[j]+arr[k] > sum) k--;
            else i++;
        }
    }
    return ans;
}

signed main() {
    int t; cin>>t; while(t--){
        cin>>n>>sum;
        arr.resize(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr.begin(), arr.end());
        cout<<solve()<<"\n";
    }
    return 0;
}