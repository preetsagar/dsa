#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k; cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) arr[i]=i+1;

    while(--k){
        next_permutation(arr.begin(),arr.end());
    }

    for(int i : arr) cout<<i<<" ";
    return 0;
}