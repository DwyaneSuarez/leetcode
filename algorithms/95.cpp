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
    vector<TreeNode*> dfs(int l, int r) {
        vector<TreeNode*> ret;
        if (l > r) {
            ret.emplace_back(nullptr);
            return ret;
        }
        for (int i = l; i <= r; ++i) {
            vector<TreeNode*> lcs = dfs(l, i - 1);
            vector<TreeNode*> rcs = dfs(i + 1, r);
            for (auto lc : lcs)
                for (auto rc : rcs) {
                    TreeNode *cur = new TreeNode(i);
                    cur->left = lc;
                    cur->right = rc;
                    ret.emplace_back(cur);
                }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0)
            return vector<TreeNode*>();
        return dfs(1, n);
    }
};