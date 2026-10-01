class Solution {
public:
    int count = 0;

    bool isSafe(int row, int col, vector<string>& board, int n) {
        int r = row, c = col;

        // Upper-left diagonal
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        r = row;
        c = col;

        // Left side
        while (c >= 0) {
            if (board[r][c] == 'Q') return false;
            c--;
        }

        r = row;
        c = col;

        // Lower-left diagonal
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r++;
            c--;
        }

        return true;
    }

    void solve(int col, vector<string>& board, int n) {
        if (col == n) {
            count++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, n);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(0, board, n);
        return count;
    }
};