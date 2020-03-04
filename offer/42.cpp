class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur += nums[i];
            if (cur < 0) {
                cur = 0;
                ans = max(ans, nums[i]);
            } else
                ans = max(ans, cur);
        }
        return ans;
    }
};