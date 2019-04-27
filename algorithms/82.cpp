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
        while (true) {
            ListNode* tmp;
            tmp = h;
            while (tmp && tmp->next && tmp->next->val == h->val)
                tmp = tmp->next;
            if (h != tmp)
                h = tmp->next;
            else
                break;
        }
        ListNode* cur = h;
        while (cur) {
            ListNode* tmp;
            tmp = cur->next;
            while (tmp && tmp->next && tmp->next->val == tmp->val)
                tmp = tmp->next;
            if (tmp != cur->next)
                cur->next = tmp->next;
            else
                cur = cur->next;
        }
        return h;
    }
};
