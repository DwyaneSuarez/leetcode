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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        que.push(root);
        while (!que.empty()) {
            TreeNode *f1 = que.front();
            que.pop();
            TreeNode *f2 = que.front();
            que.pop();
            if (!f1 && !f2)
                continue;
            if (!f1 || !f2 || f1->val != f2->val)
                return false;
            que.push(f1->left);
            que.push(f2->right);
            que.push(f1->right);
            que.push(f2->left);
        }
        return true;
    }
};