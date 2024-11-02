
#include <bits/stdc++.h>
using namespace std;


class MyCircularQueue{
    vector<int> arr;
    int n,l,r,size;
public:

    MyCircularQueue(int k){
        n=k;
        size=l=r=0;
        arr.resize(k);
    }

    bool enQueue(int value){
        if(size==n) return false;
        arr[r]=value;
        size++;
        r=(r+1)%n;
        return true;
    }

    bool deQueue(){
        if(size==0) return false;
        size--;
        l=(l+1)%n;
        return true;
    }

    int Front(){
        if(size==0) return -1;
        return arr[l];
    }

    int Rear(){
        if(size==0) return -1;
        return arr[(r-1+n)%n];
    }

    bool isEmpty(){
        return size==0;
    }

    bool isFull(){
        return size==n;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;

    int k;
    cin>>k;

    MyCircularQueue myCircularQueue(k);

    while(q--){
        string s;
        cin>>s;

        if(s=="enQueue"){
            int val;
            cin>>val;

            if(myCircularQueue.enQueue(val))
                cout<<"True\n";
            else
                cout<<"False\n";
        }
        else if(s=="deQueue"){
            if(myCircularQueue.deQueue())
                cout<<"True\n";
            else
                cout<<"False\n";
        }
        else if(s=="Front"){
            cout<<myCircularQueue.Front()<<"\n";
        }
        else if(s=="Rear"){
            cout<<myCircularQueue.Rear()<<"\n";
        }
        else if(s=="isEmpty"){
            if(myCircularQueue.isEmpty())
                cout<<"True\n";
            else
                cout<<"False\n";
        }
        else if(s=="isFull"){
            if(myCircularQueue.isFull())
                cout<<"True\n";
            else
                cout<<"False\n";
        }
        else{
            assert(1==0); //This never happen
        }
    }

    return 0;
}
