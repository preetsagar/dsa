#include <bits/stdc++.h>
using namespace std;

#define int long long
int mod=1e9+7;

int mulAndMod(int a,int b){
    return ((a%mod)*(b%mod))%mod;
}

int addAndMod(int a,int b){
    return ((a%mod)+(b%mod))%mod;
}

int binPow(int a,int b){
    if(b==0) return 1;
    if(b%2==1) return mulAndMod(a,binPow(a,b-1));
    int t=binPow(a,b/2);
    return mulAndMod(t,t);
}

int inverse(int a){
    return binPow(a,mod-2);
}

class AddMul{
public:
    vector<int> data;
    int addVal,mulVal;
    AddMul(){
        addVal=0;
        mulVal=1;
    }

    void append(int val){
        val=addAndMod(val-addVal+mod,0);
        val=mulAndMod(val,inverse(mulVal));
        data.push_back(val);
    }

    void add(long long inc){
        addVal=addAndMod(addVal,inc);
    }

    void mult(long long mul){
        addVal=mulAndMod(mul,addVal);
        mulVal=mulAndMod(mul,mulVal);
    }

    int get(int idx){
        if(idx>=data.size()) return -1;
        return addAndMod((mulAndMod(data[idx],mulVal)),addVal);
    }
};


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;

    AddMul* obj=new AddMul();

    for(int i=0; i<q; i++){
        string op;
        cin>>op;

        if(op=="append"){
            int val;
            cin>>val;
            obj->append(val);
        }
        else if(op=="add"){
            int inc;
            cin>>inc;
            obj->add(inc);
        }
        else if(op=="mult"){
            int mul;
            cin>>mul;
            obj->mult(mul);
        }
        else{
            int idx;
            cin>>idx;
            cout<<obj->get(idx)<<'\n';
        }
    }

    return 0;
}