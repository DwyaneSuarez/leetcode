/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *ret = head;
        ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur) {
            if (cur->val == val) {
                if (pre)
                    pre->next = cur->next;
                else
                    ret = cur->next;
            } else 
                pre = cur;
            cur = cur->next;
        }
        return ret;
    }
};