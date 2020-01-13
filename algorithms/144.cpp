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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *cur = root;
        vector<int> ans;
        while (cur) {
            if (cur->left) {
                TreeNode *tmp = cur->left;
                while (tmp->right && tmp->right != cur)
                    tmp = tmp->right;
                if (tmp->right != cur) {
                    ans.emplace_back(cur->val);
                    tmp->right = cur;
                    cur = cur->left;
                } else {
                    cur = cur->right;
                    tmp->right = nullptr;
                }
            } else {
                ans.emplace_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
};
