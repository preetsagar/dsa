#include <bits/stdc++.h>
using namespace std;

int n;
string ans;

void solve(int level,int open,int close){
    if(level==n){
        if(open==close){
            cout<<ans<<"\n";
        }
        return;
    }

    // place '('
    if(open<(n/2)){   /* pruning */
        ans.push_back('(');
        solve(level+1,open+1,close);
        ans.pop_back();
    }

    // place ')'
    if(open>close){   /* pruning */
        ans.push_back(')');
        solve(level+1,open,close+1);
        ans.pop_back();
    }
}
int main(){
    cin>>n;
    solve(0,0,0);
    return 0;
}