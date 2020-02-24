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
        ListNode vhead(0);
        vhead.next = head;
        ListNode *cur = head ? head->next : NULL;
        ListNode *pre = head;
        while (cur) {
            ListNode *tmp = cur->next;
            cur->next = vhead.next;
            pre->next = tmp;
            vhead.next = cur;
            cur = tmp;
        }
        return vhead.next;
    }
};