class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long acc = 0;
        for (int num: nums) acc ^= num;

        long long mask = acc & (-acc);
        vector<int> ans(2, 0);
        for (int num: nums) {
            if (mask & num) {
                ans[0] ^= num;
            } else {
                ans[1] ^= num;
            }
        }
        return ans;
    }
};
