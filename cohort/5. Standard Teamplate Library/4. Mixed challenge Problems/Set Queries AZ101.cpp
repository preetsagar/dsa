#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        set<int> s,ns;

        while(n--) {
            int a,b;
            cin>>a>>b;
            if(a==1){
                ns.erase(b);
                s.insert(b);
                if(s.find(b+1)==s.end()) ns.insert(b+1);
            }
            else{
                if(s.find(b)==s.end()) cout<<b<<"\n";
                else cout<<*(ns.upper_bound(b))<<"\n";
            }
        }
    }
    return 0;
}

/*
Thodi manmaaniya ho

Thodi nadaaniyan ho

Ho shararatein bhi thodi zara

Thodi beimaaniya ho

Door pareshaniya ho

Jaake duniya se keh do zara...

Befikra bhi hona zaroori hai

Befikri mein khona zaroori hai
*/
