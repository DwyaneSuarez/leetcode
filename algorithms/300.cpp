class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        for (int i = 0; i < nums.size(); ++i) {
            *lower_bound(dp.begin(), dp.begin() + nums.size(), nums[i]) = nums[i];
        }
        return lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin();
    }
};