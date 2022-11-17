class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> left, right, count;
        int max_cnt = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (left.count(num) == 0) {
                left[num] = i;
            }
            right[num] = i;
            ++count[num];
            max_cnt = max(max_cnt, count[num]);
        }

        int ans = INT_MAX;
        for (const auto& [num, cnt]: count) {
            if (cnt == max_cnt) {
                ans = min(ans, right[num] - left[num] + 1);
            }
        }
        return ans;
    }
};
