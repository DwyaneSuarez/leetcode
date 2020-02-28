class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while (n > 0) {
            --n;
            int cur = n % 26;
            ret += 'A' + cur;
            n /= 26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};