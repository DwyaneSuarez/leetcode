class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        int min_num = nums[0], max_num = nums[0];
        for (int i = 1; i < n; ++i)
            min_num = min(min_num, nums[i]), max_num = max(max_num, nums[i]);
        int bin_size = (max_num - min_num) / n + 1;
        vector<int> min_vec(n, INT_MAX);
        vector<int> max_vec(n, INT_MIN);
        for (int i = 0; i < n; ++i) {
            int idx = (nums[i] - min_num) / bin_size;
            min_vec[idx] = min(min_vec[idx], nums[i]);
            max_vec[idx] = max(max_vec[idx], nums[i]);
        }
        int prev = max_vec[0];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (min_vec[i] != INT_MAX) {
                ans = max(ans, min_vec[i] - prev);
                prev = max_vec[i];
            }
        }
        return ans;
    }
};
