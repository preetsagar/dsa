#include<bits/stdc++.h>
using namespace std;


long andProduct(long a,long b){
    long ans=0;
    for(int i=0; i<33; i++){
        long cnt1=(a/(1LL<<(i+1))*(1LL<<i))+max(0LL,((a%(1LL<<(i+1)))-(1LL<<i)));
        long cnt2=(b/(1LL<<(i+1))*(1LL<<i))+max(0LL,((b%(1LL<<(i+1)))-(1LL<<i)));

        if(cnt2-cnt1==(b-a)){
            ans+=(1LL<<i);
        }
    }
    return ans;
}