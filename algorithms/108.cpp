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
    TreeNode* partition(vector<int>& nums, size_t l, size_t r) {
        size_t mid = (l + r) / 2;
        TreeNode *cur = new TreeNode(nums[mid]);
        TreeNode *lc = mid - l ? partition(nums, l, mid) : nullptr;
        TreeNode *rc = r - (mid + 1) ? partition(nums, mid + 1, r) : nullptr;
        cur->left = lc;
        cur->right = rc;
        return cur;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return nullptr;
        return partition(nums, 0, len);
    }
};