class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int cnt = 1;
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == ans)
                ++cnt;
            else {
                if (cnt > 0)
                    --cnt;
                else {
                    cnt = 1;
                    ans = nums[i];
                }
            }
        }
        return ans;
    }
};