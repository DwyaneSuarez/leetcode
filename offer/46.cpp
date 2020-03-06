class Solution {
public:
    int translateNum(int num) {
        vector<int> d;
        do {
            d.push_back(num % 10);
            num /= 10;
        } while (num > 0);
        reverse(d.begin(), d.end());
        vector<int> dp(d.size());
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] += dp[i - 1];
            if (d[i - 1] == 1 || (d[i - 1] == 2 && d[i] <= 5))
                dp[i] += i >= 2 ? dp[i - 2] : 1;
        }
        return dp[d.size() - 1];
    }
};