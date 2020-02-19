class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3)
            return n - 1;
        vector<int> vec(n + 1);
        vec[0] = 0;
        vec[1] = 1;
        vec[2] = 2;
        vec[3] = 3;
        for (int i = 4; i <= n; ++i)
            for (int j = 0; j <= i / 2; ++j)
                vec[i] = max(vec[i], vec[j] * vec[i - j]);
        return vec[n];
    }
};