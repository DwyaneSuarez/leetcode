class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return;
        int i = 0, l = 0, r = n - 1;
        while (i <= r) {
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                l++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[r]);
                r--;
            } else
                i++;
        }
    }
};
