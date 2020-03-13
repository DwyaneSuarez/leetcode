class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zero = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        for (int i = zero + 1; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] == 1)
                continue;
            if (nums[i] == nums[i - 1])
                return false;
            zero -= nums[i] - nums[i - 1] - 1;
            if (zero < 0)
                return false; 
        }
        return true;
    }
};