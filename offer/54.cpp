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
    void dfs(TreeNode *cur, int k, int &i, int &ans) {
        if (!cur)
            return;
        if (cur->right)
            dfs(cur->right, k, i, ans);
        ++i;
        if (i == k) {
            ans = cur->val;
            return;
        }
        if (cur->left)
            dfs(cur->left, k, i, ans);
    }
    int kthLargest(TreeNode* root, int k) {
        int i = 0;
        int ans = 0;
        dfs(root, k, i, ans);
        return ans;
    }
};