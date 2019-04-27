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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* h = head;
        ListNode* pre = 0;
        ListNode* cur = head;
        while (cur) {
            if (pre == 0 || pre->val != cur->val)
                pre = cur;
            else
                pre->next = cur->next;
            cur = cur->next;
        }
        return h;
    }
};
