#include <bits/stdc++.h>
using namespace std;

int tc, n;
string str;
map<string, bool> dict;
int dp[1100];

bool rec(int level){
    if(level==-1) return true;

    if(dp[level]!=-1) return dp[level];

    bool ans = false;
    string tmp = "";
    for(int j=level; j>=max(0, level-20); j--){
        tmp = str[j] + tmp;
        if(dict[tmp]){
            ans |= rec(j-1);
        }
    }

    return dp[level] = ans;
}

int main() {
    cin>>tc; while(tc--){
        cin>>n>>str;
        dict.clear();
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            string t; cin>>t;
            dict[t] = true;
        }

        cout<< (rec(str.size()-1) ? "Yes" : "No") <<'\n';
    }
    return 0;
}