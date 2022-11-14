class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        /*
        DP的常规写法如下:
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0] - fee;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
        }
        return dp[n - 1][0];
        */
        //下面是DP压缩空间复杂度为O(1)之后的写法
        int a = 0;
        int b = -prices[0] - fee;
        for (int i = 1; i < n; ++i) {
            int ac = a, bc = b;
            a = max(ac, bc + prices[i]);
            b = max(bc, ac - prices[i] - fee);
        }
        return a;
    }
};
