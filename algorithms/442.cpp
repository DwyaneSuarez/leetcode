class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums[abs(nums[i]) - 1] *= -1;
            if (nums[abs(nums[i]) - 1] > 0)
                ret.push_back(abs(nums[i]));
        }
        return ret;
    }
};
