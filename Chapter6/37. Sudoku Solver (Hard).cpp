class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }

    bool backtrack(vector<vector<char>>& board, int row, int col) {
        // base case
        if (col == 9) return backtrack(board, row + 1, 0);
        if (row == 9) return true;
        if (board[row][col] != '.') return backtrack(board, row, col + 1);

        for (char c = '1'; c <= '9'; c++) {
            if (!check(board, row, col, c)) continue;
            board[row][col] = c;
            if (backtrack(board, row, col + 1)) return true;
            board[row][col] = '.';
        }
        return false;
    }

    bool check(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            if (board[(row / 3) * 3 + i / 3][col / 3 * 3 + i % 3] == c) return false;
        }
        return true;
    }
};
