class Solution {
public:
    const int kMod = 1e9 + 7;
    int cuttingRope(int n) {
        long long ans = 1;
        if (n <= 3)
            return n - 1;
        if (n % 3 == 1) {
            ans = 4;
            n -= 4;
        } else if (n % 3 == 2) {
            ans = 2;
            n -= 2;
        }
        for (int i = 0; i < n / 3; ++i)
            ans = ans * 3 % kMod;
        return ans;
    }
};