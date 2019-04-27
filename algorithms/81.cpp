class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return false;
        int l = 0, r = len - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (nums[l] < nums[mid]) {
                l = mid;
            } else if (nums[l] == nums[mid]) {
                ++l;
            } else {
                r = mid;
            }
            if (l + 1 == r)
                l = r;
        }
        int cut = l;
        l = 0, r = cut - 1;
        while (l < r && nums[l] <= target && nums[r] >= target) {
            int mid = (l + r + 1) / 2;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (nums[l] == target)
            return true;
        l = cut, r = len - 1;
        while (l < r && nums[l] <= target && nums[r] >= target) {
            int mid = (l + r + 1) / 2;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (nums[l] == target)
            return true;
        else
            return false;
    }
};
