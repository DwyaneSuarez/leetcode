class Solution {
public:
    bool can(string s, unordered_set<string>& dict) {
        int n = s.size();
        if (n == 0)
            return true;
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
    void dfs(string s, int start, vector<int> &idx, unordered_set<string> &dict, vector<string> &ans) {
        if (start == s.size()) {
            string str;
            int pre = 0;
            for (auto id : idx) {
                if (pre)
                    str += " ";
                str += s.substr(pre, id - pre);
                pre = id;
            }
            ans.emplace_back(str);
            return;
        }
        string str;
        for (int i = start; i < s.size(); ++i) {
            str += s[i];
            if (dict.count(str) && can(s.substr(i + 1), dict)) {
                idx.emplace_back(i + 1);
                dfs(s, i + 1, idx, dict, ans);
                idx.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        vector<int> idx;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        dfs(s, 0, idx, dict, ans);
        return ans;
    }
};
