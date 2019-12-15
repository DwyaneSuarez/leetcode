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
        vector<int> ret;
        if (!root)
            return ret;
        stack<pair<TreeNode*, bool>> s;
        s.push({root, true});
        while (!s.empty()) {
            TreeNode *cur = s.top().first;
            bool state = s.top().second;
            if (state) {
                if (cur->left)
                    s.push({cur->left, true});
                else 
                    s.top().second = false;
            } else {
                ret.emplace_back(cur->val);
                s.pop();
                if (cur->right)
                    s.push({cur->right, true});
                else if (!s.empty())
                    s.top().second = false;
            }
        }
        return ret;
    }
};