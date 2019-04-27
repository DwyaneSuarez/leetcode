class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0;
        int idx = 0;
        while (r < nums.size()) {
            while (r < nums.size() && nums[l] == nums[r])
                r++;
            nums[idx++] = nums[l];
            if (r - l >= 2)
                nums[idx++] = nums[l];
            l = r;
        }
        return idx;
    }
};
