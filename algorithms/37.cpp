class Solution {
public:
    bool dfs(int idx, bool r[][9], bool c[][9], bool s[][9], int bound, vector<pair<int, int>>& blank, vector<vector<char>>& board) {
        if (idx == bound) {
            return true;
        }
        int row = blank[idx].first;
        int col = blank[idx].second;
        int box = row / 3 * 3 + col / 3;
        for (int cur = 0; cur < 9; cur++) {
            if (!r[row][cur] && !c[col][cur] && !s[box][cur]) {
                r[row][cur] = c[col][cur] = s[box][cur] = true;
                board[row][col] = cur + 1 + '0';
                bool ok = dfs(idx + 1, r, c, s, bound, blank, board);
                if (ok)
                    return true;
                r[row][cur] = c[col][cur] = s[box][cur] = false;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][9], col[9][9], sqr[9][9];
        vector<pair<int, int>> blank;
        for (int i = 0; i < 9; i++) {
            memset(row, 0, sizeof(row));
            memset(col, 0, sizeof(col));
            memset(sqr, 0, sizeof(sqr));
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    blank.push_back({i, j});
                else {
                    int cur = board[i][j] - '0';
                    row[i][cur - 1] = true;
                    col[j][cur - 1] = true;
                    int x = i / 3, y = j / 3;
                    sqr[x * 3 + y][cur - 1] = true;
                }
        }
        int bound = blank.size();
        dfs(0, row, col, sqr, bound, blank, board);
    }
};
