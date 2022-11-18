class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == 0) return 0;
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);
        if (root->val >= p->val && root->val <= q->val) return root;
        if (root->val < p->val) return lowestCommonAncestor(root->right, p, q);
        return lowestCommonAncestor(root->left, p, q);
    }
};
