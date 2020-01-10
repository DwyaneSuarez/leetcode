class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cur = 1 << i;
            int cnt = 0;
            for (auto num : nums) {
                if (num & cur)
                    ++cnt;
            }
            if (cnt % 3)
                ans += cur;
        }
        return ans;
    }
};
