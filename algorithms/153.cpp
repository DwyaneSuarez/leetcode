class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int l = 0, r = nums.size() - 1;
        if (nums[l] <= nums[r])
            return nums[l];
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= nums[0])
                l = mid + 1;
            else
                r = mid;
        }
        return nums[l];
    }
};
