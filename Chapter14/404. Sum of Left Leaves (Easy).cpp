class Solution {
    int ans = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        traverse(root, false);
        return ans;
    }

    void traverse(TreeNode* root, bool isLeft) {
        if (!root) return;
        if (!root->left && !root->right && isLeft) {
            ans += root->val;
        }
        traverse(root->left, true);
        traverse(root->right, false);
    }
};
