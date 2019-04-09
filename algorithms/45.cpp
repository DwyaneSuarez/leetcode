class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
            return 0;
        int r = 0;
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < len; i++) {
            r = max(r, i + nums[i]);
            if (r >= len - 1)
                return ans + 1;
            if (cur == i) {
                ans++;
                cur = r;
            }
        }
        return ans;
    }
};
