class Solution {
public:
    vector<double> twoSum(int n) {
        vector<double> dp(n * 6);
        for (int i = 0; i < 6; ++i)
            dp[i] = 1.0 / 6;
        for (int i = 2; i <= n; ++i) {
            for (int j = i * 6 - 1; j >= 0; --j) {
                dp[j] = 0;
                for (int k = 1; k <= min(6, j); ++k) {
                    dp[j] += dp[j - k];
                }
                dp[j] /= 6;
            }
        }
        return vector<double>(dp.begin() + n - 1, dp.end());
    }
};