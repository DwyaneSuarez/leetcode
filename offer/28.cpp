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
    bool check(TreeNode *a, TreeNode *b) {
        if (!a && !b)
            return true;
        if (!a || !b)
            return false;
        if (a->val != b->val)
            return false;
        return check(a->right, b->left) && check(a->left, b->right);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};