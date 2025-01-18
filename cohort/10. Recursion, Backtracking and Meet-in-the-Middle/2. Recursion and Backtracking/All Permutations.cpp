#include <bits/stdc++.h>
using namespace std;

int n;
map<int,int>mp;
vector<int> curr;

void rec(int level){
    if(level==n){
        for(int i : curr){
            cout<<i<<" ";
        }
        cout<<"\n";
        return;
    }

    for(auto i:mp){
        if(i.second>0){
            mp[i.first]--;
            curr.push_back(i.first);
            rec(level+1);
            curr.pop_back();
            mp[i.first]++;
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int t; cin>>t; mp[t]++;
    }
    rec(0);
    return 0;
}