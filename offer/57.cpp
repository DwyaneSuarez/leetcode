class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return {};
        int p = 0, q = nums.size() - 1;
        while (p < q) {
            if (nums[p] + nums[q] == target)
                return {nums[p], nums[q]};
            else if (nums[p] + nums[q] < target)
                ++p;
            else
                --q;
        }
        return {};
    }
};