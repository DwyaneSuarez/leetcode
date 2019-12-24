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
    int ans = INT_MIN;
    int dfs(TreeNode *cur) {
        int lc = cur->left ? max(dfs(cur->left), 0) : 0;
        int rc = cur->right ? max(dfs(cur->right), 0) : 0;
        ans = max(ans, cur->val + lc + rc);
        return max(lc, rc) + cur->val;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};