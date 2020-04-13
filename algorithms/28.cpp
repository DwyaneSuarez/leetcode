class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if (n == 0)
            return 0;
        vector<int> next(n);
        next[0] = 0;
        int i = 1, j = 0;
        for (; i < n; ++i) {
            while (j > 0 && needle[j] != needle[i])
                j = next[j - 1];
            if (needle[i] == needle[j])
                next[i] = ++j;
            else
                next[i] = 0;
        }
        i = 0, j = 0;
        while (i < m) {
            while (j > 0 && haystack[i] != needle[j])
                j = next[j - 1];
            if (haystack[i] == needle[j])
                ++i, ++j;
            else
                ++i;
            if (j == n)
                return i - n;
        }
        return -1;
    }
};