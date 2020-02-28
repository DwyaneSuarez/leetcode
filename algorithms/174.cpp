class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        if (n == 0)
            return 0;
        int m = dungeon[0].size();
        if (m == 0)
            return 0;
        vector<int> dp(m);
        dp[m - 1] = 1 - min(0, dungeon[n - 1][m - 1]);
        for (int i = m - 2; i >= 0; i--) {
            dp[i] = max(dp[i + 1] - dungeon[n - 1][i], 1);
        }
        for (int i = n - 2; i >= 0; i--) {
            dp[m - 1] = max(dp[m - 1] - dungeon[i][m - 1], 1);
            for (int j = m - 2; j >= 0; j--) {
                dp[j] = max(min(dp[j], dp[j + 1]) - dungeon[i][j], 1);
            }
        }
        return dp[0];
    }
};