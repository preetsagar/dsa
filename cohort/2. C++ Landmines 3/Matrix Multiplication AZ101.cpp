#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;while(t--){
        int n,m,p;
        cin>>n>>m>>p;

        vector<vector<int>> arr1(n,vector<int>(m));
        vector<vector<int>> arr2(m,vector<int>(p));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr1[i][j];
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<p; j++){
                cin>>arr2[i][j];
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<p; j++){
                int t=0;
                for(int k=0; k<m; k++){
                    t+=(arr1[i][k]*arr2[k][j]);
                }
                cout<<t<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}