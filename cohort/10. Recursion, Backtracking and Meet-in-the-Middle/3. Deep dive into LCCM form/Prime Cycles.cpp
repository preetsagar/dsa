#include <bits/stdc++.h>
using namespace std;

int n,ans;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
vector<int> arr;
map<vector<int>,int> mp;

bool check(int cur,int last,int mask){
    if(mask&(1<<(cur-1))){
        for(int i=0; i<15; i++){
            if(prime[i]==(cur+last)) return true;
        }
    }
    return false;
}

void solve(int level,int mask,int last,bool even){
    if(level==n){
        for(int i=0; i<15; i++){
            if(prime[i]==(arr[0]+last)){
                ans++;
                break;
            }
        }
        return;
    }

    for(int cur=(even ? 2 : 1); cur<=n; cur+=2){
        if(check(cur,last,mask)){
            mask^=(1<<(cur-1));       // setting
            arr.push_back(cur);
            solve(level+1,mask,cur,!even);
            mask^=(1<<(cur-1));       // resetting
            arr.pop_back();
        }
    }
}

int main(){
    cin>>n;
    int mask=(1<<n)-1;
    mask^=2;
    arr.push_back(2);
    solve(1,mask,2,0);
    cout<<ans;
    return 0;
}