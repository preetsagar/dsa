#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr,taken(13,0),fact(14,1);
vector<int> ans;
int sizeOfArr=0;


void solve(int k){
    int count=0;
    for(int i=0; i<arr.size(); i++){
        if(taken[i]==0){
            count+=fact[sizeOfArr-1];
            if(k<=count){
                ans.push_back(arr[i]);
                taken[i]=1;
                sizeOfArr--;
                solve(k-(count-fact[sizeOfArr]));
                break;
            }
        }
    }
}

int main(){
    int k;
    cin>>n>>k;

    if(n>13){
        for(int i=n; i>n-13; i--){
            arr.push_back(i);
        }
        reverse(arr.begin(),arr.end());
        for(int i=1; i<=n-13; i++){
            cout<<i<<" ";
        }
    }
    else{
        for(int i=1; i<=n; i++){
            arr.push_back(i);
        }
    }
    sizeOfArr=arr.size();

    for(int i=1; i<14; i++){
        fact[i]=fact[i-1]*i;
    }

    solve(k);
    for(int i : ans) cout<<i<<" ";cout<<"\n";
    return 0;
}