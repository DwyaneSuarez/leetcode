class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        int x = n + m - 2;
        int y = min(m, n) - 1;
        int a = 1, b = 1;
        for (int i = x - y + 1; i <= x; i++) {
            int t1 = i;
            int t2 = i - x + y;
            int red = __gcd(t1, t2);
            t1 /= red;
            t2 /= red;
            red = __gcd(a, t2);
            t2 /= red;
            a /= red;
            red = __gcd(b, t1);
            b /= red;
            t1 /= red;
            a *= t1;
            b *= t2;
            red = __gcd(a, b);
            a /= red;
            b /= red;
        }
        return a;
    }
};
