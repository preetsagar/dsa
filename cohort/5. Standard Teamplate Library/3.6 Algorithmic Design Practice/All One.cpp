#include <bits/stdc++.h>
using namespace std;

class AllOne{
public:

    map<string,int> m_key;
    map<int,set<string>> m_freq;

    AllOne(){

    }

    void inc(string key){

        if(m_key.find(key)!=m_key.end()){
            int val=m_key[key];
            m_freq[val].erase(key);
            if(m_freq[val].empty()) m_freq.erase(val);
        }

        m_key[key]++;

        int val=m_key[key];

        m_freq[val].insert(key);
    }

    void dec(string key){

        if(m_key.find(key)!=m_key.end()){
            int val=m_key[key];
            m_freq[val].erase(key);
            if(m_freq[val].empty()) m_freq.erase(val);
        }

        m_key[key]--;

        int val=m_key[key];

        if(!val) m_key.erase(key);
        else m_freq[val].insert(key);
    }

    string getMaxKey(){
        if(m_key.empty()) return "";
        int max_freq=(*m_freq.rbegin()).first;
        return (*m_freq[max_freq].rbegin());
    }

    string getMinKey(){
        if(m_key.empty()) return "";
        int min_freq=(*m_freq.begin()).first;
        return (*m_freq[min_freq].rbegin());
    }

};

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int Q;
    cin>>Q;

    AllOne allOne;

    while(Q--){
        string op;
        cin>>op;

        if(op=="inc"){
            string key;
            cin>>key;

            allOne.inc(key);
        }
        else if(op=="dec"){
            string key;
            cin>>key;

            allOne.dec(key);
        }
        else if(op=="getMaxKey"){
            cout<<allOne.getMaxKey()<<"\n";
        }
        else if(op=="getMinKey"){
            cout<<allOne.getMinKey()<<"\n";
        }
    }

    return 0;
}
