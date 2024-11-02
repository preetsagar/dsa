#include <bits/stdc++.h>
using namespace std;


class LFUCache{
public:
    int size,capacity,lfu;
    map<int,list<int>> freqMapsList;
    map<int,pair<int,int>> keyMapsValueAndFreq;
    map<int,list<int>::iterator> keyMapsIterator;

    LFUCache(int n){
        lfu=0;
        capacity=n;
        size=0;
    }

    void update(int key){
        int value=keyMapsValueAndFreq[key].first;
        int freq=keyMapsValueAndFreq[key].second;

        freqMapsList[freq].erase(keyMapsIterator[key]);
        if(freqMapsList[freq].empty()&&lfu==freq) lfu++;
        freqMapsList[freq+1].push_back(key);
        keyMapsIterator[key]=--freqMapsList[freq+1].end();
        keyMapsValueAndFreq[key]={value,freq+1};
    }

    int get(int key){
        if(keyMapsValueAndFreq.find(key)==keyMapsValueAndFreq.end()){
            return -1;
        }
        update(key);
        return keyMapsValueAndFreq[key].first;
    }

    void put(int key,int value){
        if(capacity==0) return;
        if(keyMapsValueAndFreq.find(key)!=keyMapsValueAndFreq.end()){
            keyMapsValueAndFreq[key]={value,keyMapsValueAndFreq[key].second};
            update(key);
        }
        else{
            if(capacity==size){
                int lfuKey=freqMapsList[lfu].front();
                freqMapsList[lfu].pop_front();
                keyMapsValueAndFreq.erase(lfuKey);
                keyMapsIterator.erase(lfuKey);
                size--;
            }
            keyMapsValueAndFreq[key]={value,1};
            freqMapsList[1].push_back(key);
            keyMapsIterator[key]=--freqMapsList[1].end();
            lfu=1;
            size++;
        }
    }

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    LFUCache* obj=new LFUCache(n);
    while(q--){
        string op;
        cin>>op;
        if(op=="get"){
            int key;
            cin>>key;
            cout<<obj->get(key)<<"\n";
        }
        else if(op=="put"){
            int key,value;
            cin>>key>>value;
            obj->put(key,value);
        }
    }
}