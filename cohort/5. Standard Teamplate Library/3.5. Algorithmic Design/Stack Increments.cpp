#include <bits/stdc++.h>
using namespace std;

class CustomStack{
public:
    int size,capacity;
    vector<pair<int,int>> data;
    CustomStack(int maxSize){
        size=0;
        capacity=maxSize;
        data.resize(maxSize);
    }

    void push(int x){
        if(size==capacity) return;
        data[size++]={x,0};
    }

    int pop(){
        if(size==0) return -1;
        auto top=data[--size];
        if(size>0) data[size-1].second+=top.second;
        return top.first+top.second;
    }

    void increment(int k,int val){
        if(size<k){
            k=size;
        }
        data[k-1].second+=val;
    }

    void print(){
        for(auto i:data) cout<<"("<<i.first<<","<<i.second<<") ";cout<<endl;
    }
};

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int maxSize;
    cin>>maxSize;

    int q;
    cin>>q;

    CustomStack* customStack=new CustomStack(maxSize);

    for(int itr=0; itr<q; itr++){
        string op;
        cin>>op;

        if(op=="push"){
            int x;
            cin>>x;

            customStack->push(x);
        }
        else if(op=="pop"){
            cout<<customStack->pop()<<"\n";
        }
        else if(op=="inc"){
            int k,val;
            cin>>k>>val;
            customStack->increment(k,val);
        }
        // customStack->print();
    }

}
