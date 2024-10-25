#include <bits/stdc++.h>
using namespace std;

template<typename T>
class MyPriorityQueue{
    T* data;
    int capacity,count;

public:

    MyPriorityQueue(){
        capacity=4;
        count=0;
        data=new T[capacity];
    }

    ~MyPriorityQueue(){
        delete[] data;
    }

    void resize(int newCapacity){
        T* newData=new T[newCapacity];
        capacity=newCapacity;
        for(int i=0; i<count; i++){
            newData[i]=data[i];
        }
        delete[] data;
        data=newData;
    }

    void shiftUp(int idx){
        int parent=(idx-1)/2;
        while(idx>0&&data[parent]<data[idx]){
            swap(data[idx],data[parent]);
            swap(idx,parent);
            parent=(idx-1)/2;
        }
    }

    void shiftDown(int idx){
        // print();
        int leftChildIdx=idx*2+1;
        int rightChildIdx=idx*2+2;
        int largest=idx;
        if(leftChildIdx < count&&data[leftChildIdx] > data[largest]) largest=leftChildIdx;
        if(rightChildIdx < count&&data[rightChildIdx] > data[largest]) largest=rightChildIdx;
        if(idx!=largest){
            swap(data[idx],data[largest]);
            shiftDown(largest);
        }
    }

    void push(T newData){
        if(count==capacity) resize(capacity*2);
        data[count]=newData;
        shiftUp(count);
        count++;
    }

    void pop(){
        if(count==0) return;
        swap(data[count-1],data[0]);
        count--;
        shiftDown(0);
    }

    T top(){
        return data[0];
    }

    bool empty(){
        return count==0;
    }

    int size(){
        return count;
    }

    void print(){
        for(int i=0; i<count; i++) cout<<data[i]<<" ";cout<<"\n";
    }
};




int main(){
    // Example usage
    MyPriorityQueue<int> myPriorityQueue;

    myPriorityQueue.push(3);
    myPriorityQueue.push(1);
    myPriorityQueue.push(4);
    myPriorityQueue.push(1);
    myPriorityQueue.push(5);

    // myPriorityQueue.pop();

    cout<<"Priority Queue size: "<<myPriorityQueue.size()<<endl;

    while(!myPriorityQueue.empty()){
        // myPriorityQueue.print();
        cout<<"Top element: "<<myPriorityQueue.top()<<endl;
        myPriorityQueue.pop();
    }

    return 0;
}