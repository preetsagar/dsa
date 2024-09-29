#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--){
        int q;cin>>q;
        set<int> _set;
        while(q--){
            int t; cin>>t;
            _set.insert(t);
        }
        cout<<_set.size()<<"\n";
    }
    return 0;
}