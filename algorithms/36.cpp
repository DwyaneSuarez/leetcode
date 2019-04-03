class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[10], col[10], sqr[10];
        for (int i = 0; i < 9; i++) {
            memset(row, 0, sizeof(row));
            memset(col, 0, sizeof(col));
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int cur = board[i][j] - '0';
                    if (row[cur])
                        return false;
                    row[cur] = true;
                }
                if (board[j][i] != '.') {
                    int cur = board[j][i] - '0';
                    if (col[cur])
                        return false;
                    col[cur] = true;
                }
            }
            if (i % 3 == 0) {
                for (int j = 0; j < 9; j += 3) {
                    memset(sqr, 0, sizeof(sqr));
                    for (int x = 0; x < 3; x++)
                        for (int y = 0; y < 3; y++) {
                            if (board[i + x][j + y] != '.') {
                                int cur = board[i + x][j + y] - '0';
                                if (sqr[cur])
                                    return false;
                                sqr[cur] = true;
                            }
                        }
                }
            }
        }
        return true;
    }
};
