class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool state = n % 2;
        n /= 2;
        while (n > 0) {
            bool cur = n % 2;
            if (state == cur)
                return false;
            state = cur;
            n /= 2;
        }
        return true;
    }
};