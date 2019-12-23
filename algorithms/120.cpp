class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size(), 0);
        int n = triangle.size();
        if (n <= 0)
            return 0;
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i] = triangle[i][i] + dp[i - 1]; 
            for (int j = i - 1; j >= 1; --j)
                dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
            dp[0] += triangle[i][0];
        }
        int ans = dp[0];
        for (int i = 1; i < n; ++i)
            ans = min(ans, dp[i]);
        return ans;
    }
};