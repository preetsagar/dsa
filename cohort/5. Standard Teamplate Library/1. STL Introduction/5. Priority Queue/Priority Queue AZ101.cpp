#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--){
        int q;cin>>q;
        priority_queue<int> pq;
        while(q--){
            string s;
            cin>>s;
            if(s=="add"){
                int x; cin>>x;
                pq.push(x);
            }
            else if(s=="print"){
                if(!pq.empty()) cout<<pq.top()<<"\n";
                else cout<<"0\n";
            }
            else if(s=="remove"){
                if(!pq.empty()) pq.pop();
            }
        }
    }
    return 0;
}