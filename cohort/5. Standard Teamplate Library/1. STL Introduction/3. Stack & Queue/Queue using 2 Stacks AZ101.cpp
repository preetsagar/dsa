#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--){
        int q1;cin>>q1;
        stack<int> st1,st2;
        while(q1--){
            string s;
            cin>>s;
            if(s=="push"){
                int x; cin>>x;
                st1.push(x);
            }
            else if(s=="front"){
                if(st2.empty()){
                    while(!st1.empty()){
                        st2.push(st1.top());
                        st1.pop();
                    }
                }
                cout<<st2.top()<<"\n";
            }
            else if(s=="pop"){
                if(st2.empty()){
                    while(!st1.empty()){
                        st2.push(st1.top());
                        st1.pop();
                    }
                }
                cout<<st2.top()<<"\n";
                st2.pop();
            }
        }
    }
    return 0;
}