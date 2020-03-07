class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> vec;
        vec.reserve(n);
        vec.push_back(1);
        long long x = 0, y = 0, z = 0;
        for (int i = 1; i < n; ++i) {
            long long cur = min(vec[x] * 2, min(vec[y] * 3, vec[z] * 5));
            vec.push_back(cur);
            // 因为可能有重复数，所以每个都要判断！
            if (cur == vec[x] * 2)
                ++x;
            if (cur == vec[y] * 3)
                ++y;
            if (cur == vec[z] * 5)
                ++z;
        }
        return vec.back();
    }
};