class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int b = 0;
        while (i < n) {
            i = b;
            while (i < n && s[i] != ' ')
                ++i;
            reverse(&s[b], &s[i]);
            b = i + 1;
        }
        return s;
    }
};