#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> arr(100010);
map<int, int> m;

int main() {
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        m[arr[i]]++;
    }

    if(n%k!=0){
        cout<<"No";
        return 0;
    }

    for(auto i:m){
        if(i.second==0) continue;

        for(int j=i.first; j<i.first+k; j++){
            if(m[j]<i.second){
                cout<<"No";
                return 0;
            }
            m[j]-=i.second;
        }
    }
    cout<<"Yes";
    
    return 0;
}