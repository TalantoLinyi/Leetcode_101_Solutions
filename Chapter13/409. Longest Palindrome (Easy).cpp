class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c: s) {
            count[c]++;
        }
        int flag = 0, ans = 0;
        for (const auto& [c, cnt]: count) {
            if (cnt % 2) flag = 1;
            ans += cnt - cnt % 2;
        }
        return ans + flag;
    }
};
