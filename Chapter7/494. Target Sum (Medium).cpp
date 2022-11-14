class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < target || (sum - target) % 2 == 1) return 0;
        sum = (sum - target) / 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int num: nums) {
            for (int j = sum; j >= num; --j) {
                dp[j] = dp[j] + dp[j - num];
            }
        }
        return dp[sum];
    }
};
