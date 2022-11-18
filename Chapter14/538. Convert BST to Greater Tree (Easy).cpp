class Solution {
    int acc = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }

    void traverse(TreeNode* node) {
        if (node == nullptr) return;
        traverse(node->right);
        acc += node->val;
        node->val = acc;
        traverse(node->left);
    }
};
