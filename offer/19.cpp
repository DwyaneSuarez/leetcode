class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1));
        dp[0][0] = true;
        for (int i = 1; i <= lenp; ++i)
            dp[0][i] = p[i - 1] == '*' ? dp[0][i - 2] : false;
        for (int i = 1; i <= lens; ++i) {
            char ch = s[i - 1];
            for (int j = 1; j <= lenp; ++j) {
                char pat = p[j - 1];
                if (ch == pat || pat == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (pat == '*') {
                    char pre = p[j - 2];
                    dp[i][j] = dp[i][j - 2] | (dp[i - 1][j] & (ch == pre)) | (dp[i - 1][j] & (pre == '.'));
                }
            }
        }
        return dp[lens][lenp];
    }
};