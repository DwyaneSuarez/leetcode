class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> cnt;
        vector<char> chvec;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (cnt.count(ch) == 0)
                chvec.push_back(ch);
            ++cnt[ch];
        }
        for (auto ch : chvec)
            if (cnt[ch] == 1)
                return ch;
        return ' ';
    }
};