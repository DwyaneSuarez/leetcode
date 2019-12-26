class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        if (len == 0)
            return 0;
        vector<vector<bool>> isPalindrome(len, vector<bool>(len, false));
        for (int i = 0; i < len; ++i)
            isPalindrome[i][i] = true;
        for (int i = 0; i < len - 1; ++i)
            if (s[i] == s[i + 1])
                isPalindrome[i][i + 1] = true;
        for (int l = 3; l <= len; ++l) 
            for (int b = 0; b <= len - l; ++b)
                isPalindrome[b][b + l - 1] = isPalindrome[b + 1][b + l - 2] && (s[b] == s[b + l - 1]);
        vector<int> dp(len);
        for (int i = 0; i < len; ++i) {
            dp[i] = isPalindrome[0][i] ? 0 : i;
            for (int j = i - 1; j >= 0; --j) {
                if (isPalindrome[j + 1][i])
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[len - 1];
    }
};