#include <bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue{
    deque<int> frontQueue,backQueue;
    void balance(){
        // cout<<backQueue.size()<<" "<<frontQueue.size()<<"\n";
        if(backQueue.size()>frontQueue.size()+1){
            frontQueue.push_back(backQueue.front());
            backQueue.pop_front();
        }
        if(backQueue.size()<frontQueue.size()){
            // cout<<"hit";
            backQueue.push_front(frontQueue.back());
            frontQueue.pop_back();
        }
    }
public:
    FrontMiddleBackQueue(){}

    void pushFront(int val){
        frontQueue.push_front(val);
        balance();
    }

    void pushMiddle(int val){
        backQueue.push_front(val);
        balance();
    }

    void pushBack(int val){
        backQueue.push_back(val);
        balance();
    }

    int popFront(){
        int x=-1;
        if(!frontQueue.empty()){
            x=frontQueue.front();
            frontQueue.pop_front();
        }
        else if(!backQueue.empty()){
            x=backQueue.back();
            backQueue.pop_back();
        }
        balance();
        return x;
    }

    int popMiddle(){
        int x=-1;
        if(!frontQueue.empty()&&frontQueue.size()==backQueue.size()){
            x=frontQueue.back();
            frontQueue.pop_back();
        }
        else if(!backQueue.empty()){
            x=backQueue.front();
            backQueue.pop_front();
        }
        balance();
        return x;
    }

    int popBack(){
        int x=-1;
        if(!backQueue.empty()){
            x=backQueue.back();
            backQueue.pop_back();
        }
        balance();
        return x;
    }

    void print(){
        for(int i : frontQueue) cout<<i<<" "; cout<<" : ";
        for(int i : backQueue) cout<<i<<" "; cout<<"\n";
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    FrontMiddleBackQueue* obj=new FrontMiddleBackQueue();
    for(int i=0; i<q; i++){
        string op;
        cin>>op;
        if(op=="pushFront"){
            int val;
            cin>>val;
            obj->pushFront(val);
        }
        else if(op=="pushMiddle"){
            int val;
            cin>>val;
            obj->pushMiddle(val);
        }
        else if(op=="pushBack"){
            int val;
            cin>>val;
            obj->pushBack(val);
        }
        else if(op=="popFront"){
            cout<<obj->popFront()<<'\n';
        }
        else if(op=="popMiddle"){
            cout<<obj->popMiddle()<<'\n';
        }
        else if(op=="popBack"){
            cout<<obj->popBack()<<'\n';
        }
        // obj->print();
    }
    return 0;
}
