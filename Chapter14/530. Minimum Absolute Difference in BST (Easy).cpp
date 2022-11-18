class Solution {
    int ans = 1e5 + 1;
    TreeNode* prev = nullptr;
public:
    int getMinimumDifference(TreeNode* root) {
        traverse(root);
        return ans;
    }

    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root->left);
        if (prev) {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;
        traverse(root->right);
    }
};
