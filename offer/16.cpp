class Solution {
public:
    double myPow(double x, int n) {
        int flag = n >= 0 ? 1 : -1;
        double ret = 1;
        while (n != 0) {
            if (n & 1)
                ret *= x;
            x *= x;
            n /= 2;
        }
        if (flag == -1)
            ret = 1 / ret;
        return ret;
    }
};