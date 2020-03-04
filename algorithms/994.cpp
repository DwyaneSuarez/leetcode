class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();
        if (m == 0)
            return 0;
        queue<pair<int, int>> que;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 2)
                    que.push({i * m + j, 0});
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int ans = 0;
        while (!que.empty()) {
            auto f = que.front();
            int x = f.first / m;
            int y = f.first % m;
            int d = f.second;
            que.pop();
            ans = d;
            for (int i = 0; i < 4; ++i) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == 1) 
                    que.push({xx * m + yy, d + 1}), grid[xx][yy] = 2;
            }
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 1)
                    return -1;
        return ans;
    }
};