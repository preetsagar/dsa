#include<bits/stdc++.h>
using namespace std;

template<typename T1,typename T2>
class MyPair
{
public:
    T1 first;
    T2 second;
    // Default Constructor
    MyPair(){
        first=T1();
        second=T2();
    }
    // Parameterized Constructor
    MyPair(T1 f,T2 s){
        first=T1(f);
        second=T2(s);
    }
    // Copy Constructor
    MyPair(MyPair& t){
        first=T1(t.first);
        second=T2(t.second);
    }
    // Assignment Operator
    MyPair& operator()(MyPair& t){
        first=t.first;
        second=t.second;
        return this;
    }
    // Equality Operator (==)
    bool operator==(MyPair& t){
        return (first==t.first&&second==t.second);
    }
    // Not Equal Operator (!=)
    bool operator!=(MyPair& t){
        return *this!=t;
        // return !(first==t.first && second==t.second);
    }
    void print(){
        cout<<"("<<first<<", "<<second<<")\n";
    }
};

int main(){
    MyPair<int,double> p1(10,3.14); // Parameterized constructor
    MyPair<int,double> p2(20,6.28);
    MyPair<int,double> p3=p1; // Copy constructor

    cout<<"p1: "<<p1.first<<", "<<p1.second<<endl;
    cout<<"p2: "<<p2.first<<", "<<p2.second<<endl;
    cout<<"p3: "<<p3.first<<", "<<p3.second<<endl;

    // Assignment operator
    p3=p2;

    cout<<"After assignment:"<<endl;
    cout<<"p1: "<<p1.first<<", "<<p1.second<<endl;
    cout<<"p2: "<<p2.first<<", "<<p2.second<<endl;
    cout<<"p3: "<<p3.first<<", "<<p3.second<<endl;

    // Equality operator
    if(p1==p2)
    {
        cout<<"p1 and p2 are equal."<<endl;
    }
    else
    {
        cout<<"p1 and p2 are not equal."<<endl;
    }

    // Not equal operator
    if(p2!=p3)
    {
        cout<<"p2 and p3 are not equal."<<endl;
    }
    else
    {
        cout<<"p2 and p3 are equal."<<endl;
    }

    return 0;
}


// cd '/Users/preetsagar/Projects/cp/!ignore/cohort/5. Standard Teamplate Library/5. STL Internal/' && g++ MyPair.cpp -o MyPair && '/Users/preetsagar/Projects/cp/!ignore/cohort/5. Standard Teamplate Library/5. STL Internal/MyPair'
// g++ MyPair.cpp -o rename -> ./rename
// g++ MyPair.cpp -> ./a.out