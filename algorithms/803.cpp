class Solution {
public:
    vector<int> fa, sz;
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n = grid.size();
        int m = grid[0].size();
        int len = n * m + 1;
        fa.resize(len);
        sz.resize(len);
        for (int i = 0; i < len; ++i) {
            fa[i] = i;
            sz[i] = 1;
        }
        sz[len - 1] = 0;
        for (int i = 0; i < hits.size(); ++i) {
            int x = hits[i][0];
            int y = hits[i][1];
            if (grid[x][y] == 1) {
                grid[x][y] = 2;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (grid[0][i] == 1) {
                unionxy(i, len - 1);
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    unionWASD(i, j, n, m, grid);
                }
            }
        }
        int hs = hits.size();
        vector<int> ans;
        for (int i = hs - 1; i >= 0; --i) {
            int curx = hits[i][0];
            int cury = hits[i][1];
            if (grid[curx][cury] == 0) {
                ans.push_back(0);
                continue;
            }
            grid[curx][cury] = 1;
            int count = sz[find(len - 1)];  
            unionWASD(curx, cury, n, m, grid);
            int newCount = sz[find(len - 1)];
            ans.push_back(newCount > count ? newCount - count - 1 : 0);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    void unionWASD(int x, int y, int n, int m, vector<vector<int>> &grid) {
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0) {
                unionxy(x * m + y, n * m);
                continue;
            }
            if (xx >= n || yy < 0 || yy >= m)
                continue;
            if (grid[xx][yy] == 1) {
                unionxy(x * m + y, xx * m + yy);
            }
        }
    }
    void unionxy(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            fa[px] = py;
            sz[py] += sz[px];
        }
    }
};