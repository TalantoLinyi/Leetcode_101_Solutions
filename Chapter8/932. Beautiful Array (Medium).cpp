class Solution {
    unordered_map<int, vector<int>> memo;
public:
    vector<int> beautifulArray(int n) {
        if (n == 1) return {1};
        if (memo.count(n)) return memo[n];
        vector<int> ans;
        int odds = (n + 1) / 2;
        for (int i: beautifulArray(odds)) {
            ans.push_back(2 * i - 1);
        }
        int evens = n - odds;
        for (int i: beautifulArray(evens)) {
            ans.push_back(2 * i);
        }
        return memo[n] = ans;
    }
};
