#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--){
        int q1;cin>>q1;
        stack<int> st;
        while(q1--){
            string s;
            cin>>s;
            if(s=="add"){
                int x; cin>>x;
                st.push(x);
            }
            else if(s=="print"){
                if(st.empty()) cout<<"0\n";
                else cout<<st.top()<<"\n";
            }
            else if(s=="remove"){
                if(!st.empty())  st.pop();
            }
        }
    }
    return 0;
}