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
    int dfs(TreeNode *cur) {
        if (!cur)
            return 0;
        int l = dfs(cur->left);
        if (l == -1)
            return -1;
        int r = dfs(cur->right);
        if (r == -1)
            return -1;
        return abs(l - r) <= 1 ? 1 + max(l, r) : -1;
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};