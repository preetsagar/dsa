#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--){
        int n,m; cin>>n>>m;
        set<int> A;
        while(n--) {
            int t; cin>>t; A.insert(t);
        }

        while(m--){
            int t; cin>>t;
            if(A.find(t)!=A.end()) cout<<"YES\n";
            else cout<<"NO\n";
            A.insert(t);
        }

    }
    return 0;
}