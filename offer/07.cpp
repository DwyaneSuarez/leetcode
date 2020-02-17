// 中序遍历中的元素可以用来划分树的左子树和右子树
// 以第一个元素为例，在前序遍历中找到这个这个元素，那么这个元素之前的就是左子树，之后的就是右子树
// 重复这个过程，可以将遍历不断划分，直到只剩一个元素

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
    TreeNode* partition(size_t pre_i, size_t l, size_t r, vector<int> &preorder, vector<int> &inorder) {
        size_t pivot = l;
        for (size_t i = l; i < r; ++i)
            if (inorder[i] ==   preorder[pre_i]) {
                pivot = i;
                break;
            }
        TreeNode *cur = new TreeNode(inorder[pivot]);
        TreeNode *lc = pivot - l ? partition(pre_i + 1, l, pivot, preorder, inorder) : nullptr;
        TreeNode *rc = r - (pivot + 1) ? partition(pre_i + pivot + 1 - l, pivot + 1, r, preorder, inorder) : nullptr;
        cur->left = lc;
        cur->right = rc;
        return cur;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = nullptr;
        size_t len = preorder.size();
        if (len == 0)
            return root;
        return partition(0, 0, len, preorder, inorder);
    }
};