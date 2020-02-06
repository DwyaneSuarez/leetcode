class Solution {
public:
    bool check(vector<int> &nums, int idx) {
        if (idx == 0)
            return nums[0] > nums[1];
        if (idx + 1 == nums.size())
            return nums[idx] > nums[idx - 1];
        return nums[idx] > nums[idx - 1] && nums[idx] > nums[idx + 1];
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        if (n < 1)
            return -1;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(nums, mid))
                return mid;
            if (check(nums, l))
                return l;
            if (check(nums, r))
                return r;
            if (mid == n - 1)
                return mid;
            if (nums[mid] < nums[mid + 1])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};
