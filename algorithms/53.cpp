class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] < 0) {
                sum = 0;
                ans = max(ans, nums[i]);
            } else {
                sum += nums[i];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
