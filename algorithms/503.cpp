class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && stk.top() <= nums[i]) stk.pop();
            stk.push(nums[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && stk.top() <= nums[i]) stk.pop();
            ans[i] = stk.empty() ? -1 : stk.top();
            stk.push(nums[i]);
        }
        return ans;
    }
};