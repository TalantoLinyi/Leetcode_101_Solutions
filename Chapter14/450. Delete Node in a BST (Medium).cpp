class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key) {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            TreeNode* node = root->right;
            while(node->left) node = node->left;
            root->val = node->val;
            root->right = deleteNode(root->right, node->val);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};
