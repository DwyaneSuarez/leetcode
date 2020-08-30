class Solution {
public:
    string shortestPalindrome(string s) {
        string str = "$#";
        for (int i = 0; i < s.size(); ++i) {
            str += s[i];
            str += '#';
        }
        str += '^';
        int id = 0, mx = 0;
        int len = s.size() * 2 + 3;
        vector<int> p(len);
        int maxlen = 0;
        for (int i = 1; i < len; ++i) {
            p[i] = i < mx ? min(p[2 * id - i], mx - i) : 1;
            while (str[i - p[i]] == str[i + p[i]]) ++p[i];
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (p[i] == i) {
                maxlen = max(maxlen, p[i] - 1);
            }
        }
        string ans;
        for (int i = int(s.size()) - 1; i >= maxlen; --i) ans += s[i];
        ans += s;
        return ans;
    }
};