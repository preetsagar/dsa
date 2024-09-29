#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--){
        int q;cin>>q;
        multiset<int> mset;
        while(q--){
            string s;
            cin>>s;
            if(s=="add"){
                int x; cin>>x;
                mset.insert(x);
            }
            else if(s=="print"){
                for(int i:mset) cout<<i<<" ";
                cout<<endl;
            }
            else if(s=="erase"){
                int x; cin>>x;
                if(mset.find(x)!=mset.end())    mset.erase(mset.find(x));
            }
            else if(s=="eraseall"){
                int x; cin>>x;
                if(mset.find(x)!=mset.end())    mset.erase(x);
            }
            else if(s=="find"){
                int x; cin>>x;
                if(mset.find(x)!=mset.end()) cout<<"YES\n";
                else cout<<"NO\n";
            }
            else if(s=="count"){
                int x; cin>>x;
                cout<<mset.count(x)<<"\n";
            }
            else if(s=="empty"){
                mset.clear();
            }
        }
    }
    return 0;
}