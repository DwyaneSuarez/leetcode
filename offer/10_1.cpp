class Solution {
public:
    int fib(int n) {
        int mod = 1e9 + 7;
        int a = 0, b = 1;
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        for (int i = 2; i <= n; ++i) {
            int tmp = b;
            b = (a + b) % mod;
            a = tmp;
        }
        return b;
    }
};