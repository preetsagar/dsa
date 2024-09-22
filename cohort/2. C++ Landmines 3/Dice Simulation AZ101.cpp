#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        vector<int> arr(7);
        for(int i=1; i<=6; i++) cin>>arr[i];

        string dir;
        cin>>dir;

        for(char i:dir) {
            if(i=='N') {
                int top=arr[1],north=arr[2],south=arr[5],bottom=arr[6];
                arr[1]=north;
                arr[2]=bottom;
                arr[5]=top;
                arr[6]=south;
            }
            else if(i=='S') {
                int top=arr[1],north=arr[2],south=arr[5],bottom=arr[6];
                arr[1]=south;
                arr[2]=top;
                arr[5]=bottom;
                arr[6]=north;
            }
            else if(i=='E') {
                int top=arr[1],west=arr[3],east=arr[4],bottom=arr[6];
                arr[1]=east;
                arr[3]=top;
                arr[4]=bottom;
                arr[6]=west;
            }
            else if(i=='W') {
                int top=arr[1],west=arr[3],east=arr[4],bottom=arr[6];
                arr[1]=west;
                arr[3]=bottom;
                arr[4]=top;
                arr[6]=east;
            }
        }

        cout<<arr[1]<<endl;
    }
    return 0;
}