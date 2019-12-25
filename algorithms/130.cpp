class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void dfs(int x, int y, int n, int m, vector<vector<char>> &b) {
        b[x][y] = 'X';
        for (int i = 0; i < 4; ++i) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && b[x1][y1] == 'O')
                dfs(x + dx[i], y + dy[i], n, m, b);
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<char>> b = board;
        int n = b.size();
        if (n <= 2)
            return;
        int m = b[0].size();
        if (m <= 2)
            return;
        for (int i = 0; i < m; ++i) {
            if (b[0][i] == 'O')
                dfs(0, i, n, m, b);
            if (b[n - 1][i] == 'O')
                dfs(n - 1, i, n, m, b);
        }
        for (int i = 0; i < n; ++i) {
            if (b[i][0] == 'O')
                dfs(i, 0, n, m, b);
            if (b[i][m - 1] == 'O')
                dfs(i, m - 1, n, m, b);
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (b[i][j] == 'O')
                    board[i][j] = 'X';
    }
};