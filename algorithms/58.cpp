class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        if (len == 0)
            return 0;
        int r = len - 1;
        while (!isalpha(s[r]))
            r--;
        if (r < 0)
            return 0;
        int l = r;
        while (isalpha(s[l]))
            l--;
        return r - l;
    }
};
