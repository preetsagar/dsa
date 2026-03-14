class Solution {
public:
    int solve(int n, vector<int> &arr){
        int ans = INT_MIN;
        int i=0, j=n-1;
        while(i<j){
            ans = max(ans, (min(arr[i], arr[j]) * (j-i)));
            if(arr[i] > arr[j]) j--;
            else i++;
        }
        return ans;
    }

    int maxArea(vector<int>& height) {
        int n=height.size();
        return solve(n, height);
    }
};