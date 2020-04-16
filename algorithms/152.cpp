class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pos = 1, neg = 1;
        int n = nums.size();
        int ans = nums[0];
        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0) 
                swap(pos, neg);
            pos = max(pos * nums[i], nums[i]);
            neg = min(neg * nums[i], nums[i]);
            ans = max(ans, pos);
        }
        return ans;
    }
};