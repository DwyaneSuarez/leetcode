class Solution {
public:
    int numDistinct(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        vector<long long> dp(lent + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= lens; ++i)
            for (int j = lent; j >= 1; --j)
                dp[j] += (s[i - 1] == t[j - 1] ? dp[j - 1] : 0);
        return dp[lent];
    }
};