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
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root)
            return root;
        TreeNode *mid = new TreeNode(root->val);
        mid->left = mirrorTree(root->right);
        mid->right = mirrorTree(root->left);
        return mid;
    }
};