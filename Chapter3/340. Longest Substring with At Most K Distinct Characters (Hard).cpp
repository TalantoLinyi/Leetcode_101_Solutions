class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> freq;
        int left = 0, right = 0, len = s.size(), ans = 0;
        while (right < len) {
            freq[s[right++]]++;
            if (freq.size() <= k) {
                ans = max(ans, right - left);
            }
            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }
        }
        return ans;
    }
};
