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
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> vec;
        if (root)
            que.push(root);
        while (!que.empty()) {
            TreeNode *cur = que.front();
            que.pop();
            vec.push_back(cur->val);
            if (cur->left)
                que.push(cur->left);
            if (cur->right)
                que.push(cur->right);
        }
        return vec;
    }
};