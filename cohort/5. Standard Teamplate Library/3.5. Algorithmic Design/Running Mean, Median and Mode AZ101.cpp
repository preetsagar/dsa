#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod=1e9+7;

int binpow(int a,int b){
    if(b==0) return 1;
    if(b%2==1) return (a*binpow(a,b-1))%mod;
    int t=binpow(a,b/2);
    return (t*t)%mod;
}

int inverse(int x){
    return binpow(x,mod-2);
}

class Bag{
    int sum,count;
    multiset<int> mt1,mt2;
    map<int,int> freq;
    multiset<pair<int,int>> mtFreq;

    void balance(){
        if(mt1.size()>mt2.size()+1){
            int x=*mt1.rbegin();
            mt1.erase(--mt1.end());
            mt2.insert(x);
        }
        else if(mt2.size()>mt1.size()){
            int x=*mt2.begin();
            mt2.erase(mt2.begin());
            mt1.insert(x);
        }
    }

public:
    Bag(): sum(0),count(0){}

    void insert(int x){
        count++;
        // mean
        sum+=x;
        sum%=mod;

        // Median
        if(!mt1.empty()&&x<*mt1.rbegin()) mt1.insert(x);
        else mt2.insert(x);
        balance();

        // Mode
        if(freq[x]>0) mtFreq.erase(mtFreq.find({freq[x],-x}));
        freq[x]++;
        mtFreq.insert({freq[x],-x});
    }

    void remove(int x){
        if(count==0||freq[x]==0) return;

        count--;
        sum-=x;
        sum+=mod;
        sum%=mod;

        // Median
        if(mt1.find(x)!=mt1.end()) mt1.erase(mt1.find(x));
        else mt2.erase(mt2.find(x));
        balance();

        // Mode
        mtFreq.erase({freq[x],-x});
        freq[x]--;
        if(freq[x]>0) mtFreq.insert({freq[x],-x});
    }

    int getMean(){
        if(count==0) return -1;
        return (sum*inverse(count))%mod;
    }

    int getMedian(){
        if(count==0) return -1;
        if(count%2==0){
            int a=*mt1.rbegin();
            int b=*mt2.begin();
            return ((a+b)*inverse(2))%mod;
        }
        else{
            return *mt1.rbegin();
        }
    }

    int getMode(){
        if(count==0) return -1;
        return -(*mtFreq.rbegin()).second;
    }
};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;cin>>t;while(t--){
        Bag bag;
        int q;
        cin>>q;
        while(q--){
            string str;
            cin>>str;
            int x;
            if(str=="insert"){
                cin>>x;
                bag.insert(x);
            }
            else if(str=="remove"){
                cin>>x;
                bag.remove(x);
            }
            else if(str=="getMean"){
                cout<<bag.getMean()<<"\n";
            }
            else if(str=="getMedian"){
                cout<<bag.getMedian()<<"\n";
            }
            else if(str=="getMode"){
                cout<<bag.getMode()<<"\n";
            }
        }
    }
    return 0;
}
