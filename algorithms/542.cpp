class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0)
            return vector<vector<int>>();
        int m = matrix[0].size();
        if (m == 0)
            return vector<vector<int>>();
        vector<vector<int>> ans(n, vector<int>(m));
        queue<pair<int, int>> que;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                ans[i][j] = matrix[i][j] == 0 ? 0 : INT_MAX;
                if (ans[i][j] == 0)
                    que.push({i * m + j, 0});
            }
        while (!que.empty()) {
            int cur = que.front().first;
            int dis = que.front().second;
            que.pop();
            int x = cur / m;
            int y = cur % m;
            if (dis > 0 && dis >= ans[x][y])
                continue;
            else
                ans[x][y] = dis;
            if (x - 1 >= 0) 
                que.push({(x - 1) * m + y, dis + 1});
            if (x + 1 < n)
                que.push({(x + 1) * m + y, dis + 1});
            if (y - 1 >= 0)
                que.push({x * m + y - 1, dis + 1});
            if (y + 1 < m)
                que.push({x * m + y + 1, dis + 1});
        }
        return ans;
    }
};