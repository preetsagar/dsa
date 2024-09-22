#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;cin>>t;while(t--){
        int n,m,q;cin>>n>>m>>q;
        int row=n+1+(q*n);
        int col=m+1+(q*m);

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i%(q+1)==0||j%(q+1)==0) cout<<"*";
                else{
                    if((i%(2*(q+1)))==(j%(2*(q+1)))) cout<<'\\';
                    else if((i%(2*(q+1)))+(j%(2*(q+1)))==(2*(q+1))) cout<<'/';
                    else cout<<".";
                }
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}