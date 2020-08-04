class Solution {
public:
    // w相同时h降序，这样可以对h直接使用LIS算法
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(envelopes.size(), INT_MAX);
        for (int i = 0; i < envelopes.size(); ++i) {
            *lower_bound(dp.begin(), dp.end(), envelopes[i][1]) = envelopes[i][1];
        }
        return lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin();
    }
};