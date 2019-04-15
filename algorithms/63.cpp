class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if (n == 0)
            return 0;
        vector<vector<unsigned int>> dp(2, vector<unsigned int>(n, 0));
        dp[0][0] = obstacleGrid[0][0] != 1;
        for (int i = 1; i < n; i++)
            dp[0][i] = obstacleGrid[0][i] != 1 && dp[0][i - 1];
        for (int i = 1; i < m; i++) {
            dp[i & 1][0] = obstacleGrid[i][0] == 1 ? 0 : dp[(i - 1) & 1][0];
            for (int j = 1; j < n; j++)
                dp[i & 1][j] = obstacleGrid[i][j] == 1 ? 0 : dp[(i - 1) & 1][j] + dp[i & 1][j - 1];
        }
        return dp[(m - 1) & 1][n - 1];
    }
};
