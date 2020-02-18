// 可以直接在board上做访问标记，不需要再传一个二维数组维护访问记录

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool dfs(vector<vector<char>> &board, int x, int y, string &word, int idx) {
        if (board[x][y] == 0)
            return false;
        char ch = board[x][y];
        if (word[idx] != ch)
            return false;
        board[x][y] = 0;
        if (idx + 1 == word.size())
            return true;
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size())
                if (dfs(board, xx, yy, word, idx + 1))
                    return true;
        }
        board[x][y] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if (n == 0)
            return false;
        int m = board[0].size();
        if (m == 0)
            return false;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (dfs(board, i, j, word, 0))
                    return true;
            }
        return false;
    }
};