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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return head;
        ListNode vhead(0);
        vhead.next = head;
        ListNode *cur = head;
        while (cur->next) {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = vhead.next;
            vhead.next = tmp;
        }
        return vhead.next;
    }

    /* recursion version
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *ret = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ret;
    }
    */
};
