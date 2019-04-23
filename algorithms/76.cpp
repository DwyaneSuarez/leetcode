class Solution {
public:
    string minWindow(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        int ansStart = -1, ansLen = INT_MAX;
        int hash[128] = {0};
        int cnt[128] = {0};
        int x = 0;
        for (auto ch : t)
            if (isalpha(ch))
                ++hash[ch], ++x;
        int windowSize = 0;
        for (auto ch : s.substr(0, lent))
            if (isalpha(ch) && hash[ch]) {
                ++cnt[ch];
                if (cnt[ch] <= hash[ch])
                    ++windowSize;
            }
        int l = 0, r = lent - 1;
        while (r < lens) {
            if (windowSize == x) {
                if (r - l + 1 < ansLen) {
                    ansLen = r - l + 1;
                    ansStart = l;
                }
                char ch = s[l];
                if (isalpha(ch) && hash[ch]) {
                    cnt[ch]--;
                    if (cnt[ch] < hash[ch])
                        --windowSize;
                }
                ++l;
            } else if (windowSize < x) {
                if (r + 1 >= lens)
                    break;
                char ch = s[r + 1];
                if (isalpha(ch) && hash[ch]) {
                    cnt[ch]++;
                    if (cnt[ch] <= hash[ch])
                        ++windowSize;
                }
                ++r;
            } else {
                char ch = s[l];
                if (isalpha(ch) && hash[ch]) {
                    cnt[ch]--;
                    if (cnt[ch] < hash[ch])
                        --windowSize;
                }
                ++l;
            }
        }
        return ansStart == -1 ? "" : s.substr(ansStart, ansLen);
    }
};
