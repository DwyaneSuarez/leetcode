class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int p = len - 1;
        while (p > 0) {
            if (nums[p] <= nums[p - 1])
                p--;
            else
                break;
        }
        int tmp = p;
        if (p > 0) {
            int t = p - 1;
            int q = p;
            while (q < len && nums[q] > nums[t]) q++;
            swap(nums[t], nums[q - 1]);
        }
        int l = tmp, r = len - 1;
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> origin = nums;
        do {
            ans.push_back(nums);
            nextPermutation(nums);
        } while (nums != origin);
        return ans;
    }
};
