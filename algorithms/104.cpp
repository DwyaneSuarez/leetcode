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
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> que;
        if (root)
            que.push({root, 1});
        int ans = 0;
        while (!que.empty()) {
            auto head = que.front();
            que.pop();
            ans = max(ans, head.second);
            if (head.first->left)
                que.push({head.first->left, head.second + 1});
            if (head.first->right)
                que.push({head.first->right, head.second + 1});
        }
        return ans;
    }
};