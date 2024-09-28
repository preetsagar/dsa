#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr.begin(),arr.end());

        int count=0;
        int i=0;
        while(i<n){
            if(arr[i]<=m){
                m-=arr[i];
                count++;
                i++;
            }
            else break;
        }
        cout<<count<<"\n";
    }
    return 0;
}