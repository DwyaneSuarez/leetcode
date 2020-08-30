class Solution {
public:
    string reverseWords(string s) {
        int p = 0, q = 0;
        while (p < s.size()) {
            while (p < s.size() && s[p] == ' ') ++p;
            q = p;
            while (q < s.size() && s[q] != ' ') ++q;
            int i = p, j = q - 1;
            while (i < j) {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
            p = q;
        }
        return s;
    }
};