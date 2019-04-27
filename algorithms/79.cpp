class Solution {
public:
    bool dfs(int idx, int x, int y, const int m, const int n, vector<vector<char>> &board, vector<vector<bool>> &vis, const string &word) {
        auto len = word.size();
        if (idx == len - 1)
            return true;
        if (x - 1 >= 0 && board[x - 1][y] == word[idx + 1] && !vis[x - 1][y]) {
            vis[x - 1][y] = true;
            if (dfs(idx + 1, x - 1, y, m, n, board, vis, word))
                return true;
            vis[x - 1][y] = false;
        }
        if (x + 1 < m && board[x + 1][y] == word[idx + 1] && !vis[x + 1][y]) {
            vis[x + 1][y] = true;
            if (dfs(idx + 1, x + 1, y, m, n, board, vis, word))
                return true;
            vis[x + 1][y] = false;
        }
        if (y - 1 >= 0 && board[x][y - 1] == word[idx + 1] && !vis[x][y - 1]) {
            vis[x][y - 1] = true;
            if (dfs(idx + 1, x, y - 1, m, n, board, vis, word))
                return true;
            vis[x][y - 1] = false;
        }
        if (y + 1 < n && board[x][y + 1] == word[idx + 1] && !vis[x][y + 1]) {
            vis[x][y + 1] = true;
            if (dfs(idx + 1, x, y + 1, m, n, board, vis, word))
                return true;
            vis[x][y + 1] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())
            return true;
        int m = board.size();
        int n = m == 0 ? 0 : board[0].size();
        for (int i = 0; i != m; ++i)
            for (int j = 0; j != n; ++j)
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> vis(m, vector<bool>(n, false));
                    vis[i][j] = true;
                    if (dfs(0, i, j, m, n, board, vis, word))
                        return true;
                }
        return false;
    }
};
