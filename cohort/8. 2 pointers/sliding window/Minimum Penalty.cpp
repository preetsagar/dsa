#include <bits/stdc++.h>
using namespace std;

int n,d;
vector<int> arr;
int freq[1000100];

int solve(){
    int ans=d;
    int dist=0;
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
        if(freq[arr[i]]==1) dist++;
        if(i-d>=0){
            freq[arr[i-d]]--;
            if(freq[arr[i-d]]==0) dist--;
        }
        if(i+1>=d){
            ans = min(ans, dist);
        }
    }
    for(int i=n-d; i<n; i++) freq[arr[i]]--;
    return ans;
}

int main() {
    int t; cin>>t; while(t--){
        cin>>n>>d;
        arr.resize(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        cout<<solve()<<"\n";
    }
    return 0;
}