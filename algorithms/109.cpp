/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* partition(ListNode *head, ListNode *tail) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next != tail)
                fast = fast->next;
        }
        TreeNode *cur = new TreeNode(slow->val);
        TreeNode *lc = head != slow ? partition(head, slow) : nullptr;
        TreeNode *rc = tail != slow->next ? partition(slow->next, tail) : nullptr;
        cur->left = lc;
        cur->right = rc;
        return cur;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;
        return partition(head, nullptr);
    }
};