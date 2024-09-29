#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        map<int,int> m;
        for(int i=0; i<n; i++){
            int t; cin>>t;
            m[t]++;
        }
        int count=0;
        for(auto i:m){
            // cout<<i.first<<","<<i.second<<" ";
            if(i.first!=i.second){
                if(i.first>i.second){
                    count+=i.second;
                }
                else{
                    count+=(i.second-i.first);
                }
            }
        }

        cout<<count<<"\n";
    }
    return 0;
}