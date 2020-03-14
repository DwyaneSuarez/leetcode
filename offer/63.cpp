class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int cur = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            cur = min(cur, prices[i]);
            ans = max(ans, prices[i] - cur);
        }
        return ans;
    }
};