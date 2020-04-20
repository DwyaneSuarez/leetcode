class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n);
        sum[0] = nums[0] % 2;
        unordered_map<int, int> hash;
        hash[sum[0]]++;
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i - 1] + nums[i] % 2;
            hash[sum[i]]++;
        }
        int ans = hash[k];
        for (int i = 0; i < n; ++i)
            if (hash.count(sum[i] + k)) {
                ans += hash[sum[i] + k];
            }
        return ans;
    }
};