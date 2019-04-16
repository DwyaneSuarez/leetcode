class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int l = 1, r= 46340;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (m * m <= x)
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};
