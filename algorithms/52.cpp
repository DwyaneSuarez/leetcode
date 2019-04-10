class Solution {
public:
    bool check(int x, int y, int n, vector<string>& board) {
        for (int i = 0; i < x; i++)
            if (board[i][y] == 'Q')
                return false;
            else if (x + y - i < n && board[i][x + y - i] == 'Q')
                return false;
            else if (y - x + i >= 0 && board[i][y - x + i] == 'Q')
                return false;
        return true;
    }
    void dfs(int row, int n, vector<string>& board, int& tot) {
        if (row == n) {
            tot++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (check(row, i, n, board)) {
                board[row][i] = 'Q';
                dfs(row + 1, n, board, tot);
                board[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int total = 0;
        dfs(0, n, board, total);
        return total;
    }
};
