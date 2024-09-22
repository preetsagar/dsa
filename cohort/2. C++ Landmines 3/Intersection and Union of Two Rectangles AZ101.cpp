#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;cin>>t;while(t--){
        int a,b,c,d,e,f,g,h;
        cin>>a>>b>>c>>d>>e>>f>>g>>h;

        if(e>c||a>g||f>d||b>h) {
            int ar1=((c-a)*(d-b));
            int ar2=((g-e)*(h-f));
            cout<<0<<" "<<(ar1+ar2)<<"\n";
        }
        else{
            int ar1=((c-a)*(d-b));
            int ar2=((g-e)*(h-f));
            int x=min(c,g)-max(a,e);
            int y=min(d,h)-max(b,f);
            cout<<x*y<<" "<<(ar1+ar2-(x*y))<<"\n";
        }
    }
    return 0;
}