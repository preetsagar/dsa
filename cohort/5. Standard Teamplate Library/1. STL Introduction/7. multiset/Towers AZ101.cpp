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
            int x; cin>>x;
            if(mset.empty()) mset.insert(x);
            else{
                int flag=0;
                for(int i:mset){
                    if(i>x){
                        flag=1;
                        mset.erase(mset.find(i));
                        break;
                    }
                }
                mset.insert(x);
            }
        }
        cout<<mset.size()<<"\n";
    }
    return 0;
}