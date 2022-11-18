class Solution {
    unordered_map<long long, int> preSum;
    int ans = 0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        preSum[0] = 1;
        traverse(root, targetSum, 0);
        return ans;
    }

    void traverse(TreeNode* root, int targetSum, long long curSum) {
        if (!root) return;
        curSum += root->val;
        if (preSum.count(curSum - targetSum)) {
            ans += preSum[curSum - targetSum];
        }
        preSum[curSum]++;
        traverse(root->left, targetSum, curSum);
        traverse(root->right, targetSum, curSum);
        preSum[curSum]--;
    }
};
