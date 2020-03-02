class Solution {
public:
    void dfs(string &s, int idx, vector<string> &vec) {
        if (idx == s.size()) {
            vec.push_back(s);
            return;
        }
        for (int i = idx; i < s.size(); ++i) {
            swap(s[idx], s[i]);
            dfs(s, idx + 1, vec);
            swap(s[idx], s[i]);
        }
    }
    vector<string> permutation(string s) {
        vector<string> vec;
        dfs(s, 0, vec);
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        return vec;
    }
};