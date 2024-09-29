#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--){
        int n; cin>>n;
        map<string,int> m;
        for(int i=0; i<n; i++){
            string name; cin>>name;
            if(m.find(name)==m.end()){
                m[name]++;
                cout<<"OK\n";
            }
            else{
                cout<<name<<m[name]<<"\n";
                m[name]++;
            }
        }

    }
    return 0;
}