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
    void dfs(int row, int n, vector<string>& board, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (check(row, i, n, board)) {
                board[row][i] = 'Q';
                dfs(row + 1, n, board, ans);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        dfs(0, n, board, ans);
        return ans;
    }
};
