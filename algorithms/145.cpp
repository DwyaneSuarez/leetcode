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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        stack<pair<TreeNode*, int>> tns;
        tns.push({root, 0});
        while (!tns.empty()) {
            auto &cur = tns.top();
            if (cur.second == 0) {
                cur.second = 1;
                if (cur.first->left)
                    tns.push({cur.first->left, 0});
            } else if (cur.second == 1) {
                cur.second = 2;
                if (cur.first->right)
                    tns.push({cur.first->right, 0});
            } else {
                ans.emplace_back(cur.first->val);
                tns.pop();
            }
        }
        return ans;
    }
};
