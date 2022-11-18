class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode();
        TreeNode* cur = dummy;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            TreeNode* node = st.top();
            st.pop();
            cur->right = node;
            cur = node;
            cur->left = 0;
            //----------------
            root = node->right;
        }
        cur->right = 0;
        return dummy->right;
    }
};
