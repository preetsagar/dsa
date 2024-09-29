#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--){
        int q;cin>>q;
        set<int> st;
        while(q--){
            string s;
            cin>>s;
            if(s=="add"){
                int x; cin>>x;
                st.insert(x);
            }
            else if(s=="find"){
                int x; cin>>x;
                if(st.find(x)!=st.end()) cout<<"YES\n";
                else cout<<"NO\n";
            }
            else if(s=="erase"){
                int x; cin>>x;
                st.erase(x);
            }
            else if(s=="empty"){
                st.clear();
            }
            else if(s=="print"){
                for(int i:st) cout<<i<<" ";
                cout<<"\n";
            }
        }
    }
    return 0;
}