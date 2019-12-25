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
    void dfs(TreeNode *cur, int num, int &ans) {
        num = num * 10 + cur->val;
        if (!cur->left && !cur->right) {
            ans += num;
            return;
        }
        if (cur->left)
            dfs(cur->left, num, ans);
        if (cur->right)
            dfs(cur->right, num, ans);
    }
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        else {
            int ans = 0;
            dfs(root, 0, ans);
            return ans;
        }
    }
};