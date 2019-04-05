class Solution {
public:
    void dfs(vector<int>& cur, vector<vector<int>>& ans, vector<int>& candidates, int pre, int sum, int target) {
        if (sum == target) {
            ans.push_back(cur);
            return;
        }
        int bound = candidates.size();
        for (int i = pre + 1; i < bound; i++) {
            if (i > pre + 1 && candidates[i] == candidates[i - 1])
                continue;
            if (sum + candidates[i] <= target) {
                cur.push_back(candidates[i]);
                dfs(cur, ans, candidates, i, sum + candidates[i], target);
                cur.pop_back();
            } else
                break;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(cur, ans, candidates, -1, 0, target);
        return ans;
    }
};
