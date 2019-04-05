class Solution {
public:
    void dfs(vector<int>& cur, vector<vector<int>>& ans, vector<int>& candidates, int pre, int sum, int target) {
        if (sum == target) {
            ans.push_back(cur);
            return;
        }
        int bound = candidates.size();
        for (int i = pre; i < bound; i++) {
            if (sum + candidates[i] <= target) {
                cur.push_back(candidates[i]);
                dfs(cur, ans, candidates, i, sum + candidates[i], target);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(cur, ans, candidates, 0, 0, target);
        return ans;
    }
};
