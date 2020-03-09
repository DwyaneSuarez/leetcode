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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        while (true) {
            if (!curA || !curB)
                return NULL;
            if (curA == curB)
                return curA;
            if (!curA->next && !curB->next)
                return NULL;
            curA = curA->next ? curA->next : headB;
            curB = curB->next ? curB->next : headA;
        }
        return NULL;
    }
};