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
    void dfs(TreeNode *cur, int sum, int tot, vector<int> &curNum, vector<vector<int>> &ans) {
        if (!cur)
            return;
        curNum.emplace_back(cur->val);
        if (!cur->left && !cur->right) {
            if (sum == tot + cur->val)
                ans.emplace_back(curNum);
            curNum.pop_back();
            return;            
        }
        if (cur->left)
            dfs(cur->left, sum, tot + cur->val, curNum, ans);
        if (cur->right)
            dfs(cur->right, sum, tot + cur->val, curNum, ans);
        curNum.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> cur;
        if (!root)
            return ret;
        dfs(root, sum, 0, cur, ret);
        return ret;
    }
};