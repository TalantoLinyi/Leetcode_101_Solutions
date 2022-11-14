class Solution {
    vector<int> path;
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, target, 0);
        return ans;
    }

    void backtrace(vector<int>& candidates, int target, int pos) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = pos; i < candidates.size() && candidates[i] <= target; ++i) {
            if (i > pos && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            backtrace(candidates, target - candidates[i], i + 1);
            path.pop_back();
        }
    }
};
