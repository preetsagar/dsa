#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Vector{
public:
    int size,capacity;
    T* currVector;

    Vector(){
        capacity=4;
        size=0;
        currVector=new T[4];
    }

    ~Vector(){
        delete[] currVector;
    }

    Vector(Vector& other){
        delete[] currVector;
        capacity=other.capacity;
        size=other.size;
        currVector=new T[capacity];

        for(int i=0; i<size; i++){
            currVector[i]=other[i];
        }
    }

    Vector& operator=(Vector& other){
        if(this==other) return this;

        delete[] currVector;
        capacity=other.capacity;
        size=other.size;
        currVector=new T[capacity];

        for(int i=0; i<size; i++){
            currVector[i]=other[i];
        }

        return *this;
    }

    void resize(int newSize){
        if(newSize<size) return;

        capacity=newSize;
        T* newVector=new T[capacity];
        for(int i=0; i<size; i++){
            newVector[i]=currVector[i];
        }
        delete[] currVector;
        currVector=newVector;
    }
    void push_back(T x){
        if(size==capacity) resize(2*capacity);
        currVector[size++]=x;
    }

    void pop_back(){
        --size;
    }

    T at(int x){
        return currVector[x];
    }
};

int main()
{
    // Example usage
    Vector<int> myVec;

    myVec.push_back(1);
    myVec.push_back(2);
    myVec.push_back(3);
    myVec.pop_back();
    myVec.push_back(4);

    cout<<"Element at index 2: "<<myVec.at(2)<<endl;
    cout<<"Vector size: "<<myVec.size<<endl;
    cout<<"Vector capacity: "<<myVec.capacity<<endl;

    return 0;
}