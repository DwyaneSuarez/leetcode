class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> cnt(26);
        for (int i = 0; i < A[0].size(); ++i)
            cnt[A[0][i] - 'a']++;
        for (int i = 1; i < A.size(); ++i) {
            vector<int> tmp(26);
            for (int j = 0; j < A[i].size(); ++j)
                ++tmp[A[i][j] - 'a'];
            for (int j = 0; j < 26; ++j)
                cnt[j] = min(cnt[j], tmp[j]);
        }
        vector<string> vec;
        for (int i = 0; i < 26; ++i) {
            string cur = "a";
            cur[0] += i;
            for (int j = 0; j < cnt[i]; ++j)
                vec.push_back(cur);
        }
        return vec;
    }
};