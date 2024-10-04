#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>& a,pair<int,int>& b){
    return a.second+a.first>b.second+b.first;
}

int main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<pair<int,int>> arr;
        int a,b;
        vector<int> AA(n),BB(n);
        for(int i=0; i<n; i++) cin>>AA[i];
        for(int i=0; i<n; i++) cin>>BB[i];

        for(int i=0; i<n; i++){
            arr.push_back({AA[i],BB[i]});
        }
        sort(arr.begin(),arr.end(),comp);
        long p1=0,p2=0;
        int j=0;
        for(auto i:arr){
            // cout<<"("<<i.first<<","<<i.second<<") ";
            if(j%2==0) p1+=i.first;
            else p2+=i.second;
            j++;
        }
        if(p1>p2) cout<<"Alice\n";
        else if(p1<p2) cout<<"Bob\n";
        else cout<<"Tie\n";
    }
    return 0;
}