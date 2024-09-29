#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--){
        int q;cin>>q;
        deque<int> dq;
        while(q--){
            string s;
            cin>>s;
            if(s=="insertback"){
                int x; cin>>x;
                dq.push_back(x);
            }
            else if(s=="eraseback"){
                if(dq.size()>0) dq.pop_back();
            }
            else if(s=="insertfront"){
                int x; cin>>x;
                dq.push_front(x);
            }
            else if(s=="erasefront"){
                if(dq.size()>0) dq.pop_front();
            }
            else if(s=="printfront"){
                if(dq.size()>0)
                    cout<<dq.front()<<"\n";
                else cout<<"0\n";
            }
            else if(s=="printback"){
                if(dq.size()>0)
                    cout<<dq.back()<<"\n";
                else cout<<"0\n";
            }
            else if(s=="print"){
                int x; cin>>x;
                if(dq.size()>x) cout<<dq[x]<<"\n";
                else cout<<"0\n";
            }
        }
    }
    return 0;
}