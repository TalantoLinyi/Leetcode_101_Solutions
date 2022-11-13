class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            last[s[i] - 'a'] = i;
        }
        vector<int> partitions;
        int start = 0, end = 0;
        for (int i = 0; i < len; ++i) {
            end = max(end, last[s[i] - 'a']);
            if(i == end) {
                partitions.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partitions;
    }
};
