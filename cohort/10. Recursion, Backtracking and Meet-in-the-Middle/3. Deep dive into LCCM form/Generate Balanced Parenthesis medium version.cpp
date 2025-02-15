#include <bits/stdc++.h>
using namespace std;

int n,k;
string ans;

void solve(int level,int open,int close,int depth,int mxDepth){
    if(level==n){
        if(open==close&&mxDepth==k){
            cout<<ans<<"\n";
        }
        return;
    }

    // place '('
    if(open<(n/2)&&depth<k){   /* pruning */
        ans.push_back('(');
        solve(level+1,open+1,close,depth+1,max(mxDepth,depth+1));
        ans.pop_back();
    }

    // place ')'
    if(open>close){   /* pruning */
        ans.push_back(')');
        solve(level+1,open,close+1,depth-1,max(mxDepth,depth-1));
        ans.pop_back();
    }
}
int main(){
    cin>>n>>k;
    solve(0,0,0,0,0);
    return 0;
}