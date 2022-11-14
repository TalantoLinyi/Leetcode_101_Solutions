class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, cursum = 0;
        for (int num: nums) {
            cursum += num;
            ans = max(cursum, ans);
            cursum = max(cursum, 0);
        }
        return ans;
    }
};
