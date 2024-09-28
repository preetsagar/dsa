#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--){
        int q;cin>>q;
        vector<int> arr;
        while(q--){
            string s;
            cin>>s;
            if(s=="add"){
                int x; cin>>x;
                arr.push_back(x);
            }
            else if(s=="print"){
                int i; cin>>i;
                if(arr.size()>i)   cout<<arr[i]<<"\n";
                else   cout<<0<<"\n";
            }
            else if(s=="remove"){
                arr.pop_back();
            }
            else if(s=="clear"){
                arr.clear();
            }
        }
    }
    return 0;
}