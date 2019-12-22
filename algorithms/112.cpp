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
    bool dfs(TreeNode *cur, int sum, int tot) {
        if (!cur)
            return false;
        if (!cur->left && !cur->right)
            return sum == tot + cur->val;
        return dfs(cur->left, sum, tot + cur->val) || dfs(cur->right, sum, tot + cur->val);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return root ? dfs(root, sum, 0) : false;
    }
};