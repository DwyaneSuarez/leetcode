class Solution {
public:
    int dfs(int len, int cnt1, bool limit, vector<int> &digit, vector<vector<int>> &dp) {
        if (len == 0)
            return cnt1;
        if (!limit && dp[len][cnt1])
            return dp[len][cnt1];
        int cnt = 0, up = limit ? digit[len] : 9;
        for (int i = 0; i <= up; ++i) {
            cnt += dfs(len - 1, cnt1 + (i == 1), limit && (i == up), digit, dp);
        }
        if (!limit)
            dp[len][cnt1] = cnt;
        return cnt;
    }
    int countDigitOne(int n) {
        vector<int> digit(20);
        vector<vector<int>> dp(20, vector<int>(20));
        int k = 0;
        int num = n;
        while (num) {
            digit[++k] = num % 10;
            num /= 10;
        }
        return dfs(k, 0, true, digit, dp);
    }
};