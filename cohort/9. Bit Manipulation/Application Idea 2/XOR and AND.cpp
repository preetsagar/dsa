#include <bits/stdc++.h>
using namespace std;
#define int long long


int mod=1000000007;


int nC2(int x){
    return ((x*(x-1))/2)%mod;
}


int powOf2[100001];


signed main(){
    powOf2[0]=1;
    for(int i=1; i<100001; i++){
        powOf2[i]=(2LL*powOf2[i-1])%mod;//edit
    }
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];


        // find the sum of XOR of all pairs of numbers in the array
        int sumOfXORofAllPairs=0;
        for(int i=0; i<31; i++){
            int one=0,zero=0;
            for(int j=0; j<n; j++){
                if((1<<i)&arr[j]) one++;
                else zero++;
            }
            sumOfXORofAllPairs=(sumOfXORofAllPairs+(((one*zero)%mod)*(1ll<<i))%mod)%mod;//edit
        }
        cout<<sumOfXORofAllPairs<<" ";


        // sum of XOR of all subset of numbers in the array
        int sumOfXORofAllSubset=0;
        for(int i=0; i<31; i++){
            int one=0,zero=0;
            for(int j=0; j<n; j++){
                if((1<<i)&arr[j]) one++;
                else zero++;
            }
            if(one){
                int a=powOf2[zero];
                int b=powOf2[one-1];
                sumOfXORofAllSubset=(sumOfXORofAllSubset+((1ll<<i)*((a*b)%mod))%mod)%mod;//edit
            }
        }
        cout<<sumOfXORofAllSubset<<" ";


        // find the sum of AND of all pairs of numbers in the array
        int andOfXORofAllPairs=0;
        for(int i=0; i<31; i++){
            int one=0,zero=0;
            for(int j=0; j<n; j++){
                if((1<<i)&arr[j]) one++;
                else zero++;
            }
            andOfXORofAllPairs=(andOfXORofAllPairs+(nC2(one)*(1ll<<i))%mod)%mod;
        }
        cout<<andOfXORofAllPairs<<" ";


        // sum of AND of all subset of numbers in the array
        int andOfXORofAllSubset=0;
        for(int i=0; i<31; i++){
            int one=0,zero=0;
            for(int j=0; j<n; j++){
                if((1<<i)&arr[j]) one++;
                else zero++;
            }
            int b=powOf2[one]-1;
            andOfXORofAllSubset=(andOfXORofAllSubset+((1ll<<i)*b)%mod)%mod;
        }
        cout<<andOfXORofAllSubset<<" \n";
    }
    return 0;
}