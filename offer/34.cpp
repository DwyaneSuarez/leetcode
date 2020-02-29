/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *cur, int curSum, int sum, vector<int> &path, vector<vector<int>> &ans) {
        path.push_back(cur->val);
        curSum += cur->val;
        if (!cur->left && !cur->right) {
            if (curSum == sum) {
                ans.push_back(path);
            }
            path.pop_back();
            return;
        }
        if (cur->left)
            dfs(cur->left, curSum, sum, path, ans);
        if (cur->right)
            dfs(cur->right, curSum, sum, path, ans);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> ans;
        if (root)
            dfs(root, 0, sum, path, ans);
        return ans;
    }
};