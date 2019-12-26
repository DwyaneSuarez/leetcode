class Solution {
public:
    void dfs(int idx, const string &s, const vector<vector<int>> &next, vector<string> &cur, vector<vector<string>> &ans) {
        if (idx == s.size()) {
            ans.emplace_back(cur);
            return;
        }
        for (auto i : next[idx]) {
            cur.emplace_back(s.substr(idx, i - idx + 1));
            dfs(i + 1, s, next, cur, ans);
            cur.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<vector<string>> ans;
        if (len == 0)
            return ans;
        vector<vector<bool>> isPalindrome(len, vector<bool>(len, false));
        for (int i = 0; i < len; ++i)
            isPalindrome[i][i] = true;
        for (int i = 0; i < len - 1; ++i)
            if (s[i] == s[i + 1])
                isPalindrome[i][i + 1] = true;
        for (int l = 3; l <= len; ++l) 
            for (int b = 0; b <= len - l; ++b)
                isPalindrome[b][b + l - 1] = isPalindrome[b + 1][b + l - 2] && (s[b] == s[b + l - 1]);
        vector<vector<int>> rec(len);
        for (int i = 0; i < len; ++i)
            for (int j = i; j < len; ++j)
                if (isPalindrome[i][j])
                    rec[i].emplace_back(j);
        vector<string> cur;
        dfs(0, s, rec, cur, ans);
        return ans;
    }
};