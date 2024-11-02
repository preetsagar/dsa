
#include <bits/stdc++.h>
using namespace std;


class LRUCache{
    list<pair<int,int>> dll;
    map<int,list<pair<int,int> >::iterator> mp;
    int capacity;
public:

    LRUCache(int capacity){
        this->capacity=capacity;
    }

    int get(int key){
        if(mp.find(key)==mp.end()) return -1;

        pair<int,int> tmp=*mp[key];
        dll.erase(mp[key]);
        dll.push_front(tmp);
        mp[key]=dll.begin();
        return tmp.second;
    }

    void put(int key,int value){
        if(mp.find(key)!=mp.end()){
            pair<int,int> tmp=*mp[key];
            dll.erase(mp[key]);
        }
        else if(capacity==dll.size()){
            mp.erase(dll.back().first);
            dll.pop_back();
        }
        dll.push_front({key,value});
        mp[key]=dll.begin();
    }

    void print(){
        for(auto i:dll) cout<<"("<<i.first<<","<<i.second<<") "; cout<<"\n";
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q,cap;
    cin>>q>>cap;
    LRUCache* obj=new LRUCache(cap);
    for(int i=0; i<q; i++){
        string op;
        cin>>op;
        if(op=="get"){
            int key;
            cin>>key;
            cout<<obj->get(key)<<'\n';
        }
        else{
            int key,val;
            cin>>key>>val;
            obj->put(key,val);
        }
        // obj->print();
    }

    return 0;
}
