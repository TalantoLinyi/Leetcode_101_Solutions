class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for (int col = 0; col < n; ++col) {
            dfs(board, 0, col);
            dfs(board, m-1, col);
        }
        for (int row = 1; row < m-1; ++row) {
            dfs(board, row, 0);
            dfs(board, row, n-1);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int row, int col) {
        int m = board.size(), n = board[0].size();
        if (row < 0 || row >=m || col < 0 || col >= n || board[row][col] != 'O'){
            return;
        }
        board[row][col] = '.';
        dfs(board, row + 1, col);
        dfs(board, row - 1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
    }
};
