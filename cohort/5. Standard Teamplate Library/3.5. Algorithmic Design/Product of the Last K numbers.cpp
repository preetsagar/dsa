#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod=1e9+7;

int binpow(int a,int b){
    if(b==0) return 1;
    if(b%2==1) return (a*binpow(a,b-1))%mod;
    int t=binpow(a,b/2);
    return (t*t)%mod;
}

int inverse(int x){
    return binpow(x,mod-2);
}

int mul(int a,int b){
    return ((a%mod)*(b%mod))%mod;
}

class ProductOfKNumbers{
public:
    vector<int> arr,product;
    ProductOfKNumbers(){}
    void add(int num){
        arr.push_back(num);
        if(product.size()==0){
            product.push_back(num);
        }
        else product.push_back(mul(num,product.back()));
        if(num==0) product.clear();
    }

    int getProduct(int k){
        if(product.size()<k) return 0;
        if(product.size()==k) return product.back();
        int t=product.size()-k-1;
        return mul(product.back(),inverse(product[t]));
    }

    void print(){
        cout<<"->";
        for(int i : product) cout<<i<<" "; cout<<"<-\n";
    }
};

signed main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);

    int Q;
    cin>>Q;

    ProductOfKNumbers productOfKNumbers;

    while(Q--){
        string op;
        cin>>op;

        if(op=="add"){
            int num;
            cin>>num;
            productOfKNumbers.add(num);
        }
        else{
            int k;
            cin>>k;
            cout<<productOfKNumbers.getProduct(k)<<"\n";
        }
    }

    return 0;
}