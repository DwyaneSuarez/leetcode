class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        int i = 0, j = 0;
        int asterisk = -1, match = -1;
        while (i < lens) {
            if (j < lenp && p[j] == '*') {
                match = i;
                asterisk = j;
                j++;
            } else if (j < lenp && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            } else if (asterisk >= 0) {
                i = ++match;
                j = asterisk + 1;
            } else
                return false;
        }
        while (j < lenp && p[j] == '*')
            j++;
        return j == lenp;
    }
};
