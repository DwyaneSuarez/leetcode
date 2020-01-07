class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 0)
            return -1;
        vector<int> vec;
        int n = gas.size();
        for (int i = 0; i < n; ++i)
            vec.emplace_back(gas[i] - cost[i]);
        for (int i = 0; i < n; ++i)
            vec.emplace_back(vec[i]);
        int cur = 0, cnt = 0;
        int p = 0;
        while (p < 2 * n) {
            if (cur + vec[p] >= 0) {
                cur += vec[p];
                ++p;++cnt;
                if (cnt == n) {
                    return p - n;
                }
            } else {
                cur = 0; cnt = 0;
                if (vec[p] < 0)
                    ++p;
            }
        }
        return -1;
    }
};
