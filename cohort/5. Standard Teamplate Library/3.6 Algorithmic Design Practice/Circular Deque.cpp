
#include <bits/stdc++.h>
using namespace std;


class MyCircularDeque
{
    vector<int> arr;
    int l,r, size, curSize;
public:
   
    MyCircularDeque(int k)
    {
       arr.resize(k);
       l=0;r=0;size=k;curSize=0;
    }

    bool insertFront(int value)
    {
        if(curSize==size) return false;
        l = ((l-1)+size)%size;
        arr[l]=value; 
        curSize++;
        return true;
    }

    bool insertLast(int value)
    {
        if(curSize==size) return false;
        arr[r++]=value;
        r %= size;
        curSize++;
        return true;
    }

    bool deleteFront()
    {
        if(curSize==0) return false;
        l++; l %= size;
        curSize--;
        return true;
    }

    bool deleteLast()
    {
        if(curSize==0) return false;
        r = ((r-1)+size)%size;
        curSize--;
        return true;
    }

    int getFront()
    {
        if(curSize==0) return -1;
        return arr[l];
    }

    int getRear()
    {
        if(curSize==0) return -1;
        return arr[((r-1)+size)%size];
    }

    bool isEmpty()
    {
        return curSize==0;
    }

    bool isFull()
    {
        return curSize==size;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    int k;
    cin >> k;

    MyCircularDeque myCircularDeque(k);

    while (q--)
    {
        string s;
        cin >> s;

        if (s == "insertFront")
        {
            int val;
            cin >> val;
            if (myCircularDeque.insertFront(val))
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "insertLast")
        {
            int val;
            cin >> val;
            if (myCircularDeque.insertLast(val))
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "deleteFront")
        {
            if (myCircularDeque.deleteFront())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "deleteLast")
        {
            if (myCircularDeque.deleteLast())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "getFront")
        {
            cout << myCircularDeque.getFront() << "\n";
        }
        else if (s == "getRear")
        {
            cout << myCircularDeque.getRear() << "\n";
        }
        else if (s == "isEmpty")
        {
            if (myCircularDeque.isEmpty())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "isFull")
        {
            if (myCircularDeque.isFull())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else
        {
            assert(1 == 0); //This never happen
        }
    }

    return 0;
}
