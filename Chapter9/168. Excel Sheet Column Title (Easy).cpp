class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n > 0) {
            int num = (n-1) % 26;
            ans += char('A' + num);
            n = (n-1) / 26;
        } 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
