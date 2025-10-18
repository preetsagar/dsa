#include <bits/stdc++.h>
using namespace std;


#define ll int64_t
int dp[105][100005];

int rec(int i, int sumRemaining, vector<int> &arr){
    if(sumRemaining<0) return 0;
    if(i==arr.size()){
        if(sumRemaining==0) return 1;
        return 0;
    }
    if(dp[i][sumRemaining]!=-1) return dp[i][sumRemaining];

    int ans = rec(i+1, sumRemaining, arr);
    ans |= rec(i+1, sumRemaining-arr[i], arr);

    return dp[i][sumRemaining] = ans;
}

void findSubset(int i, int sumRemaining, vector<int> &arr, vector<int> &ans){
    if(i==arr.size()){
        return;
    }

    if(rec(i+1, sumRemaining, arr)==1){
        findSubset(i+1, sumRemaining, arr, ans);
    }
    else{
        ans.push_back(i);
        findSubset(i+1, sumRemaining-arr[i], arr, ans);
    }

    return;

    // Method 2
    // while(sumRemaining){
    //     if(rec(i+1, sumRemaining-arr[i], arr)){
    //         ans.push_back(i);
    //         sumRemaining -= arr[i];
    //     }
    //     i++;
    // }
    // return;
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.
    vector<vector<int>> ans;
    memset(dp, -1, sizeof(dp));

    for(int sum:queries){
        if(rec(0, sum, arr)){
            vector<int> tmp;
            findSubset(0, sum, arr, tmp);
            ans.push_back(tmp);
        }
        else{
            ans.push_back({-1});
        }
    }
    
    return ans;
}