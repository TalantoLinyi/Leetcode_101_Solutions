class Solution {
    vector<bool> visited;
    vector<int> path;
    vector<vector<int>> ans;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        visited = vector<bool>(n, false);
        backtrace(nums, 0);
        return ans;
    }

    void backtrace(vector<int>& nums, int pos) {
        int n = nums.size();
        //base case
        if (pos == n) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            if (i && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            //backtrace template
            visited[i] = true;
            path.push_back(nums[i]);
            backtrace(nums, pos + 1);
            path.pop_back();
            visited[i] = false;
        }
    }
};
