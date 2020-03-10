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
    int dfs(TreeNode *root) {
        if (!root)
            return 0;
        int l = dfs(root->left);
        if (l == -1)
            return -1;
        int r = dfs(root->right);
        if (r == -1)
            return -1;
        return abs(l - r) <= 1 ? max(l, r) + 1 : -1;
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};