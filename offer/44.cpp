class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10)
            return n;
        int r = 1;
        long long base = 9;
        long long cur = 10;
        while (true) {
            ++r;
            base *= 10;
            cur += base * r;
            if (cur - 1 >= n)
                break;
        }
        int beg = cur - base * r;
        int num = 1;
        for (int i = 1; i < r; ++i)
            num *= 10;
        num += (n - beg) / r;
        int idx = (n - beg) % r;
        for (int i = 0; i < r - 1 - idx; ++i)
            num /= 10;
        return num % 10;
    }
};