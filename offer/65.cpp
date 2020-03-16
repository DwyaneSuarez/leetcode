class Solution {
public:
    int add(int a, int b) {
        while (b) {
            int tmp = a ^ b;
            b = (unsigned int)(a & b) << 1;
            a = tmp;
        }
        return a;
    }
};