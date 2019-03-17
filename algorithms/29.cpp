class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        else if (divisor == -1)
            return dividend == INT_MIN ? INT_MAX : -dividend;
        if (divisor == INT_MIN)
            return dividend == INT_MIN ? 1 : 0;
        int flag = 0;
        if (dividend < 0)
            flag = divisor > 0 ? -1 : 1;
        else
            flag = divisor > 0 ? 1 : -1;
        divisor = abs(divisor);
        vector<int> dvs;
        dvs.push_back(divisor);
        int cur = divisor;
        while (INT_MAX - cur >= cur) {
            cur += cur;
            dvs.push_back(cur);
        }
        int len = dvs.size();
        int p = len - 1;
        int ans = 0;
        if (dividend > 0) {
            while (dividend >= divisor) {
                if (dividend >= dvs[p]) {
                    ans += (1 << p);
                    dividend -= dvs[p];
                } else {
                    p--;
                }
            }
        } else {
            while (dividend <= -divisor) {
                if (dividend <= -dvs[p]) {
                    ans += (1 << p);
                    dividend += dvs[p];
                } else {
                    p--;
                }
            }
        }
        return flag == 1 ? ans : -ans;
    }
};
