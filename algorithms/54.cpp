class Solution {
public:
    bool check(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int dir = 0;
        vector<int> elements;
        int n = matrix.size();
        if (n == 0)
            return elements;
        int m = matrix[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int x = 0, y = -1;
        for (int i = 0; i < n * m; i++) {
            while (!check(x + dx[dir], y + dy[dir], n, m) || vis[x + dx[dir]][y + dy[dir]])
                dir = (dir + 1) % 4;
            x = x + dx[dir];
            y = y + dy[dir];
            vis[x][y] = true;
            elements.push_back(matrix[x][y]);
        }
        return elements;
    }
};
