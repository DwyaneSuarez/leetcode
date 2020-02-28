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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<pair<TreeNode*, int>> que;
        if (root)
            que.push({root, 0});
        while (!que.empty()) {
            TreeNode *cur = que.front().first;
            int d = que.front().second;
            que.pop();
            if (d + 1 > ret.size())
                ret.resize(d + 1);
            ret[d].push_back(cur->val);
            if (cur->left)
                que.push({cur->left, d + 1});
            if (cur->right)
                que.push({cur->right, d + 1});
        }
        for (int i = 1; i < ret.size(); i += 2)
            reverse(ret[i].begin(), ret[i].end());
        return ret;
    }
};