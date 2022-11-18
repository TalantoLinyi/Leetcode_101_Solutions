class Solution {
    unordered_map<int, int> num2idx;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) return nullptr;
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            num2idx[inorder[i]] = i;
        }
        return helper(postorder, 0, n - 1, n - 1);
    }

    TreeNode* helper(vector<int>& postorder, int inBegin, int inEnd, int postEnd) {
        if (inBegin == inEnd) {
            return new TreeNode(postorder[postEnd]);
        }
        if (inBegin > inEnd) {
            return nullptr;
        }
        int mid = postorder[postEnd], midIndex = num2idx[mid], rightLen = inEnd - midIndex;
        TreeNode* root = new TreeNode(mid); 
        root->left = helper(postorder, inBegin, midIndex - 1, postEnd - 1 - rightLen);
        root->right = helper(postorder, midIndex + 1, inEnd, postEnd - 1);
        return root;
    }
};
