class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        int max_cnt = 0;
        for (char c: s) {
            max_cnt = max(max_cnt, ++freq[c]);
        }
        vector<vector<char>> buckets(max_cnt + 1);
        for (const auto& [c, cnt]: freq) {
            buckets[cnt].push_back(c);
        }
        string ans;
        for (int i = max_cnt; i >= 0; --i) {          
            for (const char& c: buckets[i]) {
                ans += string(i, c);
            }
        }
        return ans;
    }
};
