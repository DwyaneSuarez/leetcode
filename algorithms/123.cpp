class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        vector<int> fvec(n, 0);
        vector<int> rvec(n, 0);
        int buy = prices[0];
        for (int i = 1; i < n; ++i) {
            buy = min(buy, prices[i]);
            fvec[i] = max(fvec[i - 1], prices[i] - buy);
        }
        int sell = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            sell = max(sell, prices[i]);
            rvec[i] = max(rvec[i + 1], sell - prices[i]);
        }
        int ans = max(fvec[n - 1], rvec[0]);
        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, fvec[i] + rvec[i + 1]);
        }            
        return ans;
    }
};