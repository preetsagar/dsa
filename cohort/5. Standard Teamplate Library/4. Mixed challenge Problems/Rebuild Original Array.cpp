#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        multiset<int> allArray,origin,generated;
        for(int i=0;i<(1<<n); i++){
            int x; cin>>x; allArray.insert(x);
        }
        generated.insert(0);
        allArray.erase(allArray.find(0));
        while(!allArray.empty()){
            auto smallest=*allArray.begin();
            origin.insert(smallest);

            vector<int> newGen;
            for(int j:generated){
                newGen.push_back(j+smallest);
            }
            for(int j:newGen){
                if(allArray.find(j)!=allArray.end()) allArray.erase(allArray.find(j));
                generated.insert(j);
            }
        }
        for(int i:origin) cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}