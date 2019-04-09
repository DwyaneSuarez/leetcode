class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if (n == 0)
            return 1;
        int flag = n > 0 ? 1 : -1;
        while (n) {
            if (n & 1)
                ans = ans * x;
            x *= x;
            n /= 2;
        }
        if (flag == -1)
            ans = 1.0 / ans;
        return ans;
    }
};
