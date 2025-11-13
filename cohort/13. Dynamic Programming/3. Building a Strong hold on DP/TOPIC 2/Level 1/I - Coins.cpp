#include <bits/stdc++.h>
using namespace std;

int n;
double arr[3100];
double dp[3100][3100];

double rec(int level, int head){
    if(level==n){
        if(2*head > n){
            return 1.0;
        }
        return 0.0;
    }
    
    if(dp[level][head]!=-1) return dp[level][head];
    
    double ans = 0;
    ans += arr[level] * rec(level+1, head+1);
    ans += (1 - arr[level]) * rec(level+1, head);
    
    return dp[level][head] = ans;
}

int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<3100; i++){
        for(int j=0; j<3100; j++) 
            dp[i][j] = -1;
    }
    double result = rec(0, 0);
    cout.setf(std::ios::fixed);
    cout << setprecision(10) << result << "\n";
    
    return 0;
}