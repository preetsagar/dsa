#include <bits/stdc++.h>
using namespace std;
#define int long long

class Box{
    map<int,int> _map;
    int sum=0;

public:
    void add(int x){
        _map[x]++;
        sum+=x;
    }
    void remove(int x){
        if(_map.find(x)!=_map.end()){
            _map[x]--;
            sum-=x;
            if(_map[x]==0) _map.erase(x);
        }
    }
    void getMin(){
        if(_map.size()==0) cout<<"-1\n";
        else cout<<((_map.begin())->first)<<"\n";
    }
    void getMax(){
        if(_map.size()==0) cout<<"-1\n";
        else cout<<((_map.rbegin())->first)<<"\n";
    }
    void getSum(){
        cout<<sum<<"\n";
    }
};

signed main() {
    int q; cin>>q;
    Box b;
    while(q--){
        int ch; cin>>ch;
        if(ch==1){
            int x; cin>>x;
            b.add(x);
        }
        else if(ch==2){
            int x; cin>>x;
            b.remove(x);
        }
        else if(ch==3){
            char x; cin>>x;
            b.getMin();
        }
        else if(ch==4){
            char x; cin>>x;
            b.getMax();
        }
        else if(ch==5){
            char x; cin>>x;
            b.getSum();
        }
    }
    return 0;
}