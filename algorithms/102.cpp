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
        vector<vector<int>> ans;
        queue<pair<TreeNode*, size_t>> que;
        if (root)
            que.push({root, 0});
        while (!que.empty()) {
            auto head = que.front();
            que.pop();
            if (head.second >= ans.size())
                ans.emplace_back(vector<int>());
            ans[head.second].emplace_back(head.first->val);
            if (head.first->left)
                que.push({head.first->left, head.second + 1});
            if (head.first->right)
                que.push({head.first->right, head.second + 1});
        }
        return ans;
    }
};