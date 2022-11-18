class Solution {
    unordered_map<int, int> num2idx;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            num2idx[postorder[i]] = i;
        }
        return helper(preorder, 0, n - 1, n - 1);
    }

    TreeNode* helper(vector<int>& preorder, int preBegin, int preEnd, int postEnd) {
        if (preBegin > preEnd) {
            return nullptr;
        }
        if (preBegin == preEnd) {
            return new TreeNode(preorder[preBegin]);
        }
        int mid = preorder[preBegin], postMid = num2idx[preorder[preBegin+1]];
        TreeNode* root = new TreeNode(mid);
        int rightLen = postEnd - 1 - postMid;
        root->left = helper(preorder, preBegin + 1, preEnd - rightLen, postMid);
        root->right = helper(preorder, preEnd - rightLen + 1, preEnd, postEnd -1);
        return root;
    }
};
