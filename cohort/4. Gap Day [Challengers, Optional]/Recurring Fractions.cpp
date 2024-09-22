#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;cin>>t;while(t--){
        int a,b;
        cin>>a>>b;
        if(a==0) { cout<<"0\n"; continue; }
        if(a%b==0) { cout<<a/b<<"\n"; continue; }

        int plus=true;
        if(a*b<0) plus=false;
        a=abs(a); b=abs(b);

        string dec="";
        map<int,int> m;
        int rem=(a%b)*10;
        int pos=0;
        while(rem&&m.find(rem)==m.end()){
            m[rem]=pos++;
            if(rem) dec+=to_string(rem/b);
            rem=(rem%b)*10;
        }

        // printing
        if(!plus) cout<<"-";
        cout<<a/b<<".";
        if(rem!=0){
            int i=0;
            while(i<dec.size()){
                if(i==m[rem]) cout<<"(";
                cout<<dec[i++];
            }
            cout<<")\n";
        }
        else cout<<dec<<"\n";

    }
    return 0;
}