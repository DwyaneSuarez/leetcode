class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0)
            return 0;
        int* next = new int[m];
        next[0] = 0;
        int i = 1, j = 0;
        while (i < m) {
            if (needle[i] == needle[j]) {
                next[i] = j + 1;
                i++;
                j++;
            } else {
                while (needle[i] != needle[j]) {
                    if (j == 0) {
                        next[i] = 0;
                        break;
                    } else {
                        j = next[j - 1];
                    }
                }
                if (needle[i] == needle[j]) {
                    next[i] = j + 1;
                    j++;
                }
                i++;
            }
        }
        i = 0, j = 0;
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j != 0)
                    j = next[j - 1];
                else {
                    i++;
                }
            }
            if (j == m) {
                delete []next;
                return i - m;
            }
        }
        delete []next;
        return -1;
    }
};
