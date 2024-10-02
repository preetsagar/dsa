#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n; while(n--){
        string s; cin>>s;
        int depth=0;
        int count=0;
        for(auto i:s){
            if(i=='(') depth++;
            else{
                depth--;
                if(depth<0) { count++;depth=0; }
            }
        }
        if(depth>0) count+=depth;
        cout<<count<<"\n";
    }
    return 0;
}