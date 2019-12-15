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
    bool dfs(TreeNode *root, int l, int r) {
        if (!root)
            return true;
        bool ret = true;
        if (root->left) {
            if (root->left->val >= root->val)
                return false;
            ret = ret && dfs(root->left, l, root->val - 1);
            if (!ret)
                return false;
        }
        if (root->right) {
            if (root->right->val <= root->val)
                return false;
            ret = ret && dfs(root->right, root->val + 1, r);
            if (!ret)
                return false;
        }
        return root->val >= l && root->val <= r;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};