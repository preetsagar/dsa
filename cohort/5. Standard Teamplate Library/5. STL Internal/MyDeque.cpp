#include <bits/stdc++.h>
using namespace std;

template<typename T>
class MyDeque{
    int currSize,capacity;
    int firstIndex,lastIndex;
    T* arr;
public:
    MyDeque(){
        capacity=4;
        currSize=0;
        arr=new T[capacity];  // Initialize with 'capacity' instead of 'currSize'
        firstIndex=0;
        lastIndex=0;
    }

    ~MyDeque(){
        delete[] arr;
    }

    void resize(int x){
        T* tmp=new T[x];
        for(int i=0; i<currSize; i++){
            tmp[i]=arr[(firstIndex+i)%capacity];  // Handle circular nature of deque
        }
        delete[] arr;
        capacity=x;
        arr=tmp;
        firstIndex=0;
        lastIndex=currSize;
    }

    void push_back(T x){
        if(currSize==capacity) resize(2*capacity);
        arr[lastIndex]=x;
        lastIndex=(lastIndex+1)%capacity;
        currSize++;
    }

    void push_front(T x){
        if(currSize==capacity) resize(2*capacity);
        firstIndex=(firstIndex-1+capacity)%capacity;
        arr[firstIndex]=x;
        currSize++;
    }

    void pop_front(){
        if(currSize==0){
            throw out_of_range("Deque is empty");
        }
        firstIndex=(firstIndex+1)%capacity;
        currSize--;
    }

    void pop_back(){
        if(currSize==0){
            throw out_of_range("Deque is empty");
        }
        lastIndex=(lastIndex-1+capacity)%capacity;
        currSize--;
    }

    T operator[](int x){
        if(x>=currSize){  // Check bounds correctly
            throw out_of_range("Index out of Bound");
        }
        return arr[(firstIndex+x)%capacity];
    }

    bool empty() const{
        return currSize==0;
    }

    int size() const{
        return currSize;
    }
};

int main(){
    // Example usage
    MyDeque<int> myDeque;

    myDeque.push_back(1);
    myDeque.push_back(2);
    myDeque.push_front(0);

    cout<<"Deque currSize: "<<myDeque.size()<<endl;

    for(int i=0; i<myDeque.size(); ++i){
        cout<<myDeque[i]<<" ";
    }
    cout<<endl;

    myDeque.pop_back();

    cout<<"Deque currSize after pop_back: "<<myDeque.size()<<endl;

    for(int i=0; i<myDeque.size(); ++i){
        cout<<myDeque[i]<<" ";
    }
    cout<<endl;

    return 0;
}