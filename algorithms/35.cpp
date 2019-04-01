class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return 0;
        if (target > nums[len - 1])
            return len;
        int l = 0, r = len - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
