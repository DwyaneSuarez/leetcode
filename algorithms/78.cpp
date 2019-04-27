class Solution {
public:
    void dfs(vector<int> &vec, vector<vector<int>> &ans, int idx, const vector<int> &nums) {
        auto bound = nums.size();
        if (idx == bound) {
            ans.push_back(vec);
            return;
        }
        dfs(vec, ans, idx + 1, nums);
        vec.push_back(nums[idx]);
        dfs(vec, ans, idx + 1, nums);
        vec.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> vec;
        dfs(vec, ret, 0, nums);
        return ret;
    }
};
