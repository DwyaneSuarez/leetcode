class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            while (l < n && nums[l] % 2 == 1)
                ++l;
            while (r >= 0 && nums[r] % 2 == 0)
                --r;
            if (l < r)
                swap(nums[l], nums[r]);
        }
        return nums;
    }
};