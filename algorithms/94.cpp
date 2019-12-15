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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        TreeNode *cur = root, *pre = nullptr;
        while (cur) {
            if (!cur->left) {
                vec.emplace_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right && pre->right != cur)
                    pre = pre->right;
                if (pre->right) {
                    pre->right = nullptr;
                    vec.emplace_back(cur->val);
                    cur = cur->right;
                } else {
                    pre->right = cur;
                    cur = cur->left;
                }
            }
        }
        return vec;
    }
};