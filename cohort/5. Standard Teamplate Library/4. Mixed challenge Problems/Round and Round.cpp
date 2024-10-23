#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> move={{0,1},{-1,0},{0,-1},{1,0}};
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        string str;
        cin>>str;

        int dir=0,x=0,y=0;

        for(char i:str) {
            if(i=='W') {
                x+=move[dir][0];
                y+=move[dir][1];
            }
            else if(i=='L') {
                dir=(dir+3)%4;
            }
            else if(i=='R') {
                dir=(dir+1)%4;
            }
        }

        if((x==0&&y==0)||dir!=0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}