#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define pii pair<ll, ll>
const int mod=1e9+7;
inline ll add(ll x,ll y) { return ((x+y)%mod+mod)%mod; }
inline ll sub(ll x,ll y) { return ((x-y)%mod+mod)%mod; }

/* #########################################################################################################################
 */

ll x,y,t;

ll solve() {
    for(int i=0; i<=3*x; i++){
        for(int j=0; j<=3*y; j++){
            if(i%3==0) cout<<"*";
            else if(j%3==0){
                cout<<"*";
            }
            else cout<<".";
        }
        cout<<endl;

    }
    return 0;
}

void input() {
    cin>>x>>y;
    solve();
}

int main() {
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>t;
    while(t--) {
        input();
    }
    return 0;
}