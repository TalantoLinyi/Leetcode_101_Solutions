class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> freqs;
        for (int num: nums) {
            ++freqs[num];
        }
        for (const auto& [num, freq]: freqs) {
            if (freqs.count(num + 1)) {
                ans = max(ans, freq + freqs[num + 1]);
            }
        }
        return ans;
    }
};
