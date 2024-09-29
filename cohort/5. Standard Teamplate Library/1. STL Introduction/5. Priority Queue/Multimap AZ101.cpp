#include <bits/stdc++.h>
using namespace std;

#define int long long

// Method 1
signed main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        map<string,queue<int>> m;

        while(n--){
            string s;
            cin>>s;
            if(s=="add"){
                string name;
                int marks;
                cin>>name>>marks;
                m[name].push(marks);
            }
            else if(s=="print"){
                string name; cin>>name;
                if(m.find(name)!=m.end()) cout<<m[name].front()<<"\n";
                else cout<<"0\n";
            }
            else if(s=="erase"){
                string name; cin>>name;
                if(m.find(name)!=m.end()) {
                    m[name].pop();
                    if(m[name].size()==0){
                        m.erase(name);
                    }
                }

            }
            else if(s=="eraseall"){
                string name; cin>>name;
                if(m.find(name)!=m.end()) {
                    m.erase(name);
                }
            }
        }
    }
    return 0;
}

// Method 2
int main() {
    IOS;
    int t;
    cin>>t;
    while(t--) {
        int q;
        cin>>q;
        multimap<string,int> m;
        while(q--) {
            string s;
            cin>>s;
            if(s=="add") {
                string x;
                int y;
                cin>>x>>y;
                m.insert({x,y});
            }
            else if(s=="erase") {
                string x;
                cin>>x;
                auto it=m.find(x);
                if(it!=m.end()) {
                    m.erase(it);
                }
            }
            else if(s=="eraseall") {
                string x;
                cin>>x;
                if(m.find(x)!=m.end()) {
                    m.erase(x);
                }
            }
            else {
                string x;
                cin>>x;
                auto it=m.find(x);
                if(it!=m.end()) {
                    cout<<it->second<<"\n";
                }
                else {
                    cout<<"0\n";
                }
            }
        }
    }
    return 0;
}