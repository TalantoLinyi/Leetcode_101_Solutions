class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 0;
        int start = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i <= j; ++i) {
                if (s[i] == s[j]){
                    if (j - i <= 2 || dp[i + 1][j - 1]) dp[i][j]=true;
                    if (dp[i][j] && j - i + 1 > maxLen) {
                        start = i;
                        maxLen = j - i + 1;
                    }
                } 
            }
        }
        return s.substr(start, maxLen);
    }
};
