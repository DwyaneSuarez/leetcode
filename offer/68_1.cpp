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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = min(p->val, q->val);
        int big = max(p->val, q->val);
        TreeNode *cur = root;
        while (true) {
            if (cur->val >= small && cur->val <= big)
                return cur;
            if (cur->val < small)
                cur = cur->right;
            else
                cur = cur->left;
        }
    }
};