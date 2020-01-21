class Solution {
public:
    string reverseWords(string s) {
        string s1;
        int b = 0;
        int e = int(s.size()) - 1;
        while (b < s.size() && s[b] == ' ')
            ++b;
        while (e >= 0 && s[e] == ' ')
            --e;
        for (int i = b; i <= e; ++i) {
            if (s[i] != ' ') {
                s1 += s[i];
            } else if (i > 0 && s[i] != s[i - 1])
                s1 += s[i];
        }
        reverse(s1.begin(), s1.end());
        auto iter1 = s1.begin();
        auto iter2 = s1.begin();
        while (iter2 != s1.end()) {
            if (*iter2 == ' ') {
                reverse(iter1, iter2);
                ++iter2;
                iter1 = iter2;
            } else
                ++iter2;
        }
        reverse(iter1, iter2);
        return s1;
    }
};
