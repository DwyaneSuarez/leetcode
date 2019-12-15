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
    void recoverTree(TreeNode* root) {
        TreeNode *cur = root, *pre = nullptr;
        TreeNode *prev = nullptr;
        TreeNode *l = nullptr, *r = nullptr;
        while (cur) {
            if (!cur->left) {
                if (prev && prev->val >= cur->val) {
                    if (!l)
                        l = prev;
                    r = cur;
                } 
                prev = cur;
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right && pre->right != cur)
                    pre = pre->right;
                if (pre->right) {
                    pre->right = nullptr;
                    if (prev && prev->val >= cur->val) {
                        if (!l)
                            l = prev;
                        r = cur;
                    }
                    prev = cur;
                    cur = cur->right;
                } else {
                    pre->right = cur;
                    cur = cur->left;
                }
            }
        }
        swap(l->val, r->val);
    }
};