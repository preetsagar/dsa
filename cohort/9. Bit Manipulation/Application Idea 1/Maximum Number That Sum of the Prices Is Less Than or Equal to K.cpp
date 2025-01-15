// link -> https://leetcode.com/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    bool check(long long mid,long long x,long long k){
        long long count=0,t=x;
        for(int i=0; i<63; i++){
            if((i+1)%x==0){
                count+=((mid/(1LL<<(i+1))*(1LL<<i))+max(0LL,((mid%(1LL<<(i+1)))-(1LL<<i))));
            }
        }
        return count<=k;
    }

    long long findMaximumNumber(long long k,int x){
        long long l=1,r=1e15;

        long long ans=-1;
        while(l<=r){
            long long mid=(l+r)/2;
            if(check(mid+1,x,k)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        return ans;
    }
};