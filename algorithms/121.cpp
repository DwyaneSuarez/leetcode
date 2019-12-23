class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if (prices.size() == 0)
            return 0;
        int sell = 0;
        for (int i = prices.size() - 1; i >= 0; --i) {
            sell = max(sell, prices[i]);
            ans = max(ans, sell - prices[i]);
        }
        return ans;
    }
};