#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;cin>>t; while(t--){
        int h,w,n; cin>>h>>w>>n;
        set<int> hz,vt;
        multiset<int> hz_mx,vt_mx;
        hz.insert(0);hz.insert(h);  hz_mx.insert(h);
        vt.insert(0);vt.insert(w);  vt_mx.insert(w);

        while(n--){
            char ch;
            int cut;
            cin>>ch>>cut;
            if(ch=='H'){
                hz.insert(cut);
                auto it=hz.find(cut);
                auto prev=--it;
                auto next=++(++it);
                int d=*next-*prev;
                int n1,n2;
                n1=cut-*prev;
                n2=*next-cut;

                hz_mx.erase(hz_mx.find(d));
                hz_mx.insert(n1);hz_mx.insert(n2);

                cout<<(*hz_mx.rbegin())*(*vt_mx.rbegin())<<"\n";
            }
            else{
                vt.insert(cut);
                auto it=vt.find(cut);
                auto prev=--it;
                auto next=++(++it);
                int d=*next-*prev;
                int n1,n2;
                n1=cut-*prev;
                n2=*next-cut;

                vt_mx.erase(vt_mx.find(d));
                vt_mx.insert(n1);vt_mx.insert(n2);

                cout<<(*hz_mx.rbegin())*(*vt_mx.rbegin())<<"\n";
            }
        }
    }
    return 0;
}