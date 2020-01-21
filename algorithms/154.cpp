class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int ans = nums[0];
        for (auto num : nums)
            ans = min(ans, num);
        return ans;
    }
};
