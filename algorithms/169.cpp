class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            cnt += ans == nums[i] ? 1 : -1;
            if (cnt < 0)
                ans = nums[i], cnt = 1;
        }
        return ans;
    }
};
