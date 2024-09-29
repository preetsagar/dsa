#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--){
        int q;cin>>q;
        map<string,int> m;
        while(q--){
            string s;
            cin>>s;
            if(s=="add"){
                string name;
                int y; cin>>name>>y;
                m[name]=y;
            }
            else if(s=="print"){
                string name; cin>>name;
                cout<<m[name]<<"\n";
            }
            else if(s=="erase"){
                string name; cin>>name;
                m.erase(name);
            }
        }
    }
    return 0;
}