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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        queue<pair<TreeNode*, int>> que;
        if (root) {
            que.push({root, 0});
        }
        int curDepth = -1;
        while (!que.empty()) {
            TreeNode *cur = que.front().first;
            int depth = que.front().second;
            que.pop();
            if (depth > curDepth) {
                curDepth = depth;
                vec.push_back(cur->val);
            }
            if (cur->right)
                que.push({cur->right, depth + 1});
            if (cur->left)
                que.push({cur->left, depth + 1});
        }
        return vec;
    }
};