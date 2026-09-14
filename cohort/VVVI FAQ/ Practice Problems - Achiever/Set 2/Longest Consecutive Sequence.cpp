
#include <bits/stdc++.h>
using namespace std;


int LongestConsecutive(vector <int>& nums) {
	unordered_map<int, int> mp;
    for(int num:nums) mp[num]++;

    int ans=0;
    for(int num:nums){
        int currLen=0;
        int seq=num;
        if(mp.find(num-1)==mp.end()){
            while(mp.find(seq)!=mp.end()){
                currLen++;
                seq++;
            }
            ans = max(ans, currLen);
        }
    }

    return ans;
}


int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector <int> nums(n);
	for (auto &i : nums)
		cin >> i;
	cout << LongestConsecutive(nums);
}
