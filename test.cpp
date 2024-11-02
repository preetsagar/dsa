#include <bits/stdc++.h>
#include <utility>
using namespace std;

#define int long long
const int mod = 1e9+7;

int binpow(int a, int b){
    if(b==0) return 1;
    if(b%2==1) return (a*binpow(a, b-1))%mod;
    else{
        int t = binpow(a, b/2);
        return (t*t)%mod;
    }
}

int inverse(int x){
    return binpow(x, mod-2);
}


class Bag{
    int sum, count;
    multiset<int> mt1, mt2;
    multiset<pair<int, int> > mtFreq;
    map<int, int> freq;

    void balance(){
        if(mt1.size() - mt2.size() > 1){
            int x = *mt1.rbegin();
            mt1.erase(--mt1.end());
            mt2.insert(x);
        }
        else if(mt2.size() > mt1.size()){
            int x = *mt2.begin();
            mt2.erase(mt2.begin());
            mt1.insert(x);
        }
    }

    public:

    Bag(){
        sum=0; count=0;
    }
    void insert(int x){
        count++;
        // mean
        sum += x;

        // median
        if(!mt1.empty()){
            if(x < *mt1.rbegin()) mt1.insert(x);
            else mt2.insert(x);
        }
        else mt1.insert(x);
        balance();

        // mode
        mtFreq.erase(make_pair(freq[x], x));
        freq[x]++;
        mtFreq.insert(make_pair(freq[x], x));

    }
    void remove(int x){
        count--;
        // mean
        sum -= x;

        // median
        if(mt1.find(x)!=mt1.end()) mt1.erase(mt1.find(x));
        else if(mt2.find(x)!=mt2.end()) mt2.erase(mt2.find(x));
        balance();

        // mode
        mtFreq.erase({freq[x], x});
        freq[x]--;
        mtFreq.insert({freq[x], x});
    }

    int getMean(){
        return sum * inverse(count);
    }

    int getMedian(){
        if(count%2==0){
            int a,b;
            a = *mt1.rbegin();
            b = *mt2.begin();
            return a*b*inverse(2);
        }
        else{
            return *mt1.rbegin();
        }
    }

    int getMode(){
        return (*mtFreq.rbegin()).second;
    }
};

signed main() {
    int t; cin>>t; while(t--){
        Bag bag;
        int q; cin>>q;
        while(q--){
            string a;cin>>a;
            int b;
            if(a=="insert"){
                cin>>b;
                bag.insert(b);
            }
            else if(a=="remove"){
                cin>>b;
                bag.remove(b);
            }
            else if(a=="getMean"){
                cout<<bag.getMean()<<"\n";
            }
            else if(a=="getMedian"){
                cout<<bag.getMedian()<<"\n";
            }
            else if(a=="getMode"){
                cout<<bag.getMode()<<"\n";
            }
        }
    }
    return 0;
}
