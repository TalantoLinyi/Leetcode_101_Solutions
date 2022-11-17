class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (r * c != m * n) return mat;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = i * n + j;
                ans[idx / c][idx % c] = mat[i][j];
            }
        }  
        return ans;
    }
};
