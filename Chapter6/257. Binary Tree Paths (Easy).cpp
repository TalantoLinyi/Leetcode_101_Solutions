class Solution {
    vector<string> ans;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }

    void dfs(TreeNode* root, string path){
        if (root->left == nullptr && root->right == nullptr) {
            path += to_string(root->val);
            ans.push_back(path);
            return;
        }
        path += to_string(root->val) + "->";
        if (root->left) dfs(root->left, path);
        if (root->right) dfs(root->right, path);
    }
};
