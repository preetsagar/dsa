
#include <bits/stdc++.h>
using namespace std;

#define int long long

map<pair<int, int>, int> dp;
int mod = 1e9+7;

int solve(vector <int>& nums, int target, int i, int sum){
    if(i==nums.size()){
        return target==sum;
    }

    if(dp.find({i, sum})!=dp.end()) return dp[{i, sum}];

    int ans = 0;
    ans += solve(nums, target, i+1, sum+nums[i]);
    ans += solve(nums, target, i+1, sum-nums[i]);

    return dp[{i, sum}]=(ans)%mod;
}

int BuildingtheSum(vector <int>& nums, int target) {
	return solve(nums, target, 0, 0);
}



signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int target;
	cin >> target;
	vector <int> nums(n);
	for (auto &i : nums)
		cin >> i;
	cout << BuildingtheSum(nums, target);
}
