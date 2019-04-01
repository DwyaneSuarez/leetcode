class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int len = nums.size();
        if (len == 0) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int l = 0, r = len - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        ans.push_back(nums[l] == target ? l : -1);
        l = 0, r = len - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        ans.push_back(nums[l] == target ? l : -1);
        return ans;
    }
};
