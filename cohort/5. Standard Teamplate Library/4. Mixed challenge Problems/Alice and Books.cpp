#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        multiset<int> mt;

        int ans=0;
        while(n--){
            int k; cin>>k;
            mt.insert(k);

            while(!mt.empty()&&*mt.begin()<=ans) mt.erase(mt.begin());

            if(mt.size()>=ans+1){
                ans++;
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
    return 0;
}