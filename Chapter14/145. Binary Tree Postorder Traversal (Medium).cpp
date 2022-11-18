class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* node;
        while (!st.empty()) {
            node = st.top(); st.pop();
            ans.push_back(node->val);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
