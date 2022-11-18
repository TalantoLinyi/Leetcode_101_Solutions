class Solution {
    int maxDepth = 0;
    int depth = 0;
    int ans;
public:
    int findBottomLeftValue(TreeNode* root) {
        traverse(root);
        return ans;
    }

    void traverse(TreeNode* root) {
        if (!root) return;
        depth++;
        if (depth > maxDepth) {
            maxDepth = depth;
            ans = root->val;
        }
        traverse(root->left);
        traverse(root->right);
        depth--;
    }
};
