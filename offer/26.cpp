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
    bool check(TreeNode *A, TreeNode *B) {
        if (!B || !A)
            return false;
        if (A->val != B->val)
            return false;
        if (B->left)
            if (!check(A->left, B->left))
                return false;
        if (B->right)
            if (!check(A->right, B->right))
                return false;
        return true;
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B || !A)
            return false;
        if (!B->left && !B->right && B->val == A->val) {
            return true;
        }
        if (B->val == A->val) {
            bool ret = true;
            if (B->left)
                ret &= check(A->left, B->left);
            if (B->right)
                ret &= check(A->right, B->right);
            if (ret)
                return true;
        } 
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};