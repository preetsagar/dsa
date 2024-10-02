#include <bits/stdc++.h>
using namespace std;

class MonotonicDeque{
    deque<int> dq;

public:
    void insert(int x){
        while(!dq.empty()&&dq.back()<x) dq.pop_back();
        dq.push_back(x);
    }
    void remove(int x){
        if(dq.front()==x) dq.pop_front();
    }
    int getMax(){
        return dq.front();
    }
    void print(){
        cout<<"Current status : ";
        for(int i:dq) cout<<i<<" ";
        cout<<"\n";
    }
};

int main() {
    int t; cin>>t; while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        // USING MULTISET
        // multiset<int> mt;
        // for(int i=0; i<n; i++){
        //     mt.insert(arr[i]);
        //     if(i-k >= 0) mt.erase(mt.find(arr[i-k]));
        //     if(mt.size()==k) cout<<(*mt.rbegin())<<" ";
        // }
        // cout<<endl;

        // USING MONOTONIC DEQUE
        MonotonicDeque mt;
        for(int i=0; i<n; i++){
            mt.insert(arr[i]);
            if(i-k>=0) mt.remove(arr[i-k]);
            if(i+1>=k) cout<<mt.getMax()<<" ";

        }
        cout<<endl;
    }
    return 0;
}