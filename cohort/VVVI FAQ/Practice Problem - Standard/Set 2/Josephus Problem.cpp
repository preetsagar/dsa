#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> arr;

int solve(int n, int k){
    if(n==1) return 0;
    
    int whoWillSurvive = solve(n-1, k);
    int y = (whoWillSurvive + k)%n;
    
    return y;
}

int main() {
    cin>>n>>k;
    cout<<solve(n,k)+1;
    return 0;
}