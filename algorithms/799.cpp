class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 2);
        dp[0].resize(1);
        dp[0][0] = poured;
        for (int i = 0; i <= query_row; ++i) {
            dp[i + 1].resize(i + 2);
            for (int j = 0; j <= i; ++j) {
                if (dp[i][j] > 1) {
                    double overflow = (dp[i][j] - 1) * 0.5;
                    dp[i + 1][j] += overflow;
                    dp[i + 1][j + 1] += overflow;
                } 
            }
        }
        return min(dp[query_row][query_glass], 1.0);
    }
};