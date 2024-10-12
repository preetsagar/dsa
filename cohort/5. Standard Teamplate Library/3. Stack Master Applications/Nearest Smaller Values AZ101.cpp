#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<int> arr(n),nse(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        // Next smaller element
        for(int i=0; i<n; i++){
            nse[i]=i-1;
            while(nse[i]!=-1&&arr[i]<=arr[nse[i]]){
                nse[i]=nse[nse[i]];
            }
        }
        for(int i=0; i<n; i++){
            cout<<nse[i]+1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}