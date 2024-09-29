#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--){
        int n,m; cin>>n>>m;
        set<int> A,B,C;
        while(n--) {
            int t; cin>>t; A.insert(t);
            C.insert(t);
        }
        while(m--) {
            int t; cin>>t; B.insert(t);
            C.insert(t);
        }
        // Union
        for(int i:C) cout<<i<<" ";
        cout<<"\n";

        // Intersection
        for(int i:A){
            if(B.find(i)!=B.end()) cout<<i<<" ";
        }
        cout<<"\n";

        // A-B
        for(int i:A){
            if(B.find(i)==B.end()) cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}