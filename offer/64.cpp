class Solution {
public:
    int sumNums(int n) {
        int ret = n;
        n && (ret += sumNums(n - 1));
        return ret;
    }
};