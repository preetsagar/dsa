#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<vector<int>> bits(n+10,vector<int>(35,0));

        for(int i=0; i<n; i++){
            cin>>arr[i];
            for(int j=0; j<31; j++){
                bits[i+1][j]=bits[i][j]+((arr[i]&(1LL<<j)) ? 1 : 0);
            }
        }

        long long x1=0,x2=0,x3=0;
        int q; cin>>q;
        while(q--){
            x1=0,x2=0,x3=0;
            int l,r; cin>>l>>r;
            int total=r-l+1;
            for(int j=30; j>=0; j--){
                int one=bits[r][j]-bits[l-1][j];
                int zero=total-one;
                if(one<zero){
                    x1|=(1LL<<j);
                }
                if(zero>0){
                    x2|=(1LL<<j);
                }
                if(one>0){
                    x3|=(1LL<<j);
                }
            }
            cout<<x1+x2+x3<<"\n";
        }
    }
    return 0;
}