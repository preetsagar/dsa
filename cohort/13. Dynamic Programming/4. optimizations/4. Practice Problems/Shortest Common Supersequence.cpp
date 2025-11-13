
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n,m;
string s,t;

int dp[1100][1100];
int back[1100][1100];

int rec(int i, int j){
    if(i==n || j==m){
        return n-i + m-j;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 1e9;
    if(s[i]==t[j]) {
        int t = 1+rec(i+1, j+1);
        if(ans > t){
            ans = t;
            back[i][j] = 0;
        }
    }

    int t = 1+rec(i+1, j);
    if(ans > t){
        ans = t;
        back[i][j] = 1;
    }
    t = 1+rec(i, j+1);
    if(ans > t){
        ans = t;
        back[i][j] = 2;
    }

    return dp[i][j] = ans;
}

string generate(int i, int j){
    if(i==n || j==m){
        return s.substr(i) + t.substr(j);
    }

    int ch = back[i][j];
    string ans = "";
    if(ch==0){
        ans += s[i];
        ans += generate(i+1, j+1);
    }
    if(ch==1){
        ans += s[i];
        ans += generate(i+1, j);
    }
    if(ch==2){
        ans += t[j];
        ans += generate(i, j+1);
    }

    return ans;
}


string ShortestCommonSupersequence(string &str1, string &str2) {
    s = str1; n=s.size();
    t = str2; m=t.size();

    memset(dp, -1, sizeof(dp));
    memset(back, -1, sizeof(back));

    rec(0, 0);
    return generate(0,0);
}
























void checker() {
    string x, y;
    cin >> x >> y;
    auto s = ShortestCommonSupersequence(x, y);
    cout << s.size() << endl;
    bool f = 1;
    int i = 0, j = 0;
    while (i < x.size() && j < s.size()) {
        if (x[i] == s[j])i++, j++;
        else j++;
    }
    if (i != x.size())f = 0;
    i = 0, j = 0;
    while (i < y.size() && j < s.size()) {
        if (y[i] == s[j])i++, j++;
        else j++;
    }
    if (i != y.size())f = 0;
    cout << f << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        checker();
        // i++;
    }
    return 0;
}
