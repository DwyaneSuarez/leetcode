class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return -1;
        int l = 0, r = len - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (nums[l] < nums[mid]) {
                l = mid;
            } else {
                r = mid;
            }
            if (l + 1 == r)
                l = r;
        }
        int cut = l;
        l = 0, r = cut - 1;
        while (l < r && nums[l] < target) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (nums[l] == target)
            return l;
        l = cut, r = len - 1;
        while (l < r && nums[l] < target) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (nums[l] == target)
            return l;
        else
            return -1;
    }
};
