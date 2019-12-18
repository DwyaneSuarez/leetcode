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
    TreeNode* partition(size_t post_i, size_t l, size_t r, vector<int> &inorder, vector<int> &postorder) {
        size_t pivot = r;
        for (size_t i = r - 1; i >= 0; --i)
            if (inorder[i] == postorder[post_i]) {
                pivot = i;
                break;
            }
        TreeNode *cur = new TreeNode(inorder[pivot]);
        TreeNode *lc = pivot - l ? partition(post_i - (r - pivot) , l, pivot, inorder, postorder) : nullptr;
        TreeNode *rc = r - (pivot + 1) ? partition(post_i - 1, pivot + 1, r, inorder, postorder) : nullptr;
        cur->left = lc;
        cur->right = rc;
        return cur;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = nullptr;
        size_t len = inorder.size();
        if (len == 0)
            return root;
        return partition(len - 1, 0, len, inorder, postorder);
    }
};