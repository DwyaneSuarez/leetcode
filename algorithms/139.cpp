class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = dict.count(s.substr(0, i + 1));
            if (dp[i]) continue;
            for (int j = 0; j < i; j++)
                if (dp[j] && dict.count(s.substr(j + 1, i - j)))
                {
                    dp[i] = true; break;
                }
        }
        return dp[n - 1];
    }
};
