#include <bits/stdc++.h>
using namespace std;

template<typename key,typename value>
class MyUnorderedMap{
    int capacity,count;
    list<pair<key,value> >* data;
    hash<key> hasher;

    int getHash(key k){
        // return k%capacity;
        return hasher(k)%capacity;
    }

public:
    MyUnorderedMap(){
        capacity=4;
        count=4;
        data=new list<pair<key,value> >[capacity];
    }
    ~MyUnorderedMap(){
        delete[] data;
    }

    void insert(key K,value V){
        int hashKey=getHash(K);
        for(auto& i:data[hashKey]){
            if(i.first==K){
                i.second=V;
                return;
            }
        }
        data[hashKey].push_back(make_pair(K,V));
        ++count;
    }

    bool get(key k,value v){
        int hashKey=getHash(k);
        for(auto i:data[hashKey]){
            if(i.first==k&&i.second==v){
                return true;
            }
        }
        return false;
    }

    bool erase(key k){
        int hashKey=getHash(k);
        for(auto it=data[hashKey].begin(); it!=data[hashKey].end(); it++){
            if(it->first==k){
                data[hashKey].erase(it);
                count--;
                return true;
            }
        }
        return false;
    }

    void print(){
        cout<<"-------------------------- "<<"\n";
        for(int j=0; j<4; j++){
            cout<<"hashKey == "<<j<<"\n";
            for(auto i:data[j]){
                cout<<i.first<<" -> "<<i.second<<"\n";
            }
        }
    }
};


int main(){
    MyUnorderedMap<int,string> myUnorderedMap;
    myUnorderedMap.insert(0,"zero");
    myUnorderedMap.insert(1,"one");
    myUnorderedMap.insert(1,"1");
    myUnorderedMap.insert(2,"two");
    myUnorderedMap.insert(3,"three");
    myUnorderedMap.insert(4,"four");
    myUnorderedMap.insert(5,"five");

    myUnorderedMap.print();
    myUnorderedMap.erase(5);
    myUnorderedMap.print();

    MyUnorderedMap<string,string> myUnorderedMap2;
    myUnorderedMap2.insert("hello","Aarigato");
    myUnorderedMap2.insert("world","Sekai");
    myUnorderedMap2.insert("thank you","Arigato");
    myUnorderedMap2.insert("good morning","Ohayou");
    myUnorderedMap2.insert("good night","Oyasumi");
    myUnorderedMap2.insert("goodbye","Sayonara");
    myUnorderedMap2.insert("love","Ai");
    myUnorderedMap2.insert("peace","Heiwa");
    myUnorderedMap2.insert("dream","Yume");
    myUnorderedMap2.insert("courage","Yuuki");
    myUnorderedMap2.insert("strength","Tsuyosa");

    // Print the map to verify the entries
    myUnorderedMap2.print();
}
