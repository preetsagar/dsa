#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<vector<int>> adj;
vector<int> arr;

signed main() {
    cin>>n;
    adj.resize(n, vector<int>(n));
    arr.resize(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>adj[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        int t; cin>>t; t--;
        arr[i]=t;
    }
    reverse(arr.begin(), arr.end());

    vector<int> ans;
    for(int k=0; k<n; k++){
        int sum=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                adj[i][j] = min(adj[i][j], adj[i][arr[k]]+adj[arr[k]][j]);
            }
        }
        for(int i=0; i<=k; i++){
            for(int j=0; j<=k; j++){
                sum += adj[arr[i]][arr[j]];
            }
        }
        ans.push_back(sum);
    }

    reverse(ans.begin(), ans.end());
    for(int i:ans) cout<<i<<" ";
    return 0;
}