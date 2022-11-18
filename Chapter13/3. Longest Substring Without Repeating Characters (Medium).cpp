class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> preIdx(128, 0);
        int ans = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (preIdx[s[i]]) {
                left = max(left, preIdx[s[i]]);
            }
            ans = max(ans, i + 1 - left);
            preIdx[s[i]] = i + 1;
        }
        return ans;
    }
};
