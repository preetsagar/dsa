#include <bits/stdc++.h>
using namespace std;

using lli=long long int;
using ld=long double;

lli a,b;

ld func(lli mid){
    return (ld) a/sqrt(mid+1)+(ld) b*mid;
}

int main(){
    cin>>a>>b;
    lli lo=0,hi=a,ans=-1;

    while(lo<=hi){
        lli mid=(lo+hi)/2;
        if(func(mid)<=func(mid+1)){
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    cout<<fixed<<setprecision(15)<<func(ans);
    return 0;
}