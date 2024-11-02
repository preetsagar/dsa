#include <bits/stdc++.h>
using namespace std;
#define int long long


class DataStructure{
    multiset<int> first,second;
    int sum,k;

public:
    DataStructure(){
        sum=0;
    }
    DataStructure(int k){
        sum=0;
        this->k=k;
    }

    void add(int x){
        first.insert(x);
        sum+=x;
        if(first.size()>k){
            int mn=*first.begin();
            sum-=mn;
            first.erase(first.begin());
            second.insert(mn);
        }
    }

    void remove(int x){
        if(second.find(x)!=second.end()){
            second.erase(second.find(x));
        }
        else if(first.find(x)!=first.end()){
            sum-=x;
            first.erase(first.find(x));
            if(!second.empty()){
                int newTopK=*(second.rbegin());
                second.erase(--second.end());
                first.insert(newTopK);
                sum+=newTopK;
            }
        }
    }

    int getTopKSum(){
        return sum;
    }

    void print(){
        for(int i : first) cout<<i<<","; cout<<" : ";
        for(int i : second) cout<<i<<","; cout<<"\n";
    }
};

signed main(){
    int q,k;cin>>q>>k;
    DataStructure ds(k);
    while(q--){
        int a,b; cin>>a;
        char skip;
        if(a==1){
            cin>>b;
            ds.add(b);
        }
        else if(a==2){
            cin>>b;
            ds.remove(b);
        }
        else if(a==3){
            cin>>skip;
            cout<<ds.getTopKSum()<<"\n";
        }
        // ds.print();
    }
    return 0;
}