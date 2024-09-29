#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--){
        int q1;cin>>q1;
        queue<int> q;
        while(q1--){
            string s;
            cin>>s;
            if(s=="add"){
                int x; cin>>x;
                q.push(x);
            }
            else if(s=="print"){
                if(q.empty()) cout<<"0\n";
                else cout<<q.front()<<"\n";
            }
            else if(s=="remove"){
                if(!q.empty())  q.pop();
            }
        }
    }
    return 0;
}