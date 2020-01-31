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
        if (!headA || !headB)
            return nullptr;
        ListNode *pA = headA;
        ListNode *pB = headB;
        ListNode *endA = nullptr;
        ListNode *endB = nullptr;
        while (pA != pB) {
            if (!pA)
                pA = headB;
            else if (pA->next)
                pA = pA->next;
            else
                endA = pA, pA = pA->next;
            if (!pB)
                pB = headA;
            else if (pB->next)
                pB = pB->next;
            else
                endB = pB, pB = pB->next;
            if (endA && endB && endA != endB)
                return nullptr;
        }
        return pA;
    }
};
