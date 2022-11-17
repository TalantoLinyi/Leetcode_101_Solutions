class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // O(nlogn)
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
            ans += nums[j] - nums[i];
        }
        return ans;
        // a better solution can use the nth_element in C++ to find the median.
        // this is a O(n) method.
    }
};
