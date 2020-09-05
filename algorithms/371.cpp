class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int ans = 0;
        int base = 1;
        while (true) {
            int cura = a & 1;
            int curb = b & 1;
            if (cura ^ curb ^ carry) ans |= base;
            carry = (cura | curb | carry) && ((cura & curb & carry) || !(cura ^ curb ^ carry));
            if (base == (1 << 31)) break; 
            base <<= 1;
            a >>= 1;
            b >>= 1;    
        }
        return ans;
    }
};