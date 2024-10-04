#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string,int>& a,pair<string,int>& b){
    return a.second<b.second;
}

int main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<pair<string,int>> arr;
        string s;
        int marks;
        while(n--){
            cin>>s>>marks;
            arr.push_back({s,marks});
        }
        sort(arr.begin(),arr.end(),comp);
        for(auto i:arr){
            cout<<i.first<<" "<<i.second<<"\n";
        }
    }
    return 0;
}