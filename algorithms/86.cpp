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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode* lptr = head;
        ListNode* lprev = start;
        while (lptr) {
            if (lptr->val < x) {
                lprev = lptr;
                lptr = lptr->next;
            } else {
                ListNode* rptr = lptr;
                ListNode* rprev = lprev;
                while (rptr && rptr->val >= x) {
                    rprev = rptr;
                    rptr = rptr->next;
                }
                if (!rptr)
                    return start->next;
                lprev->next = rptr;
                rprev->next = rptr->next;
                rptr->next = lptr;
                lprev = rptr;
            }
        }
        return start->next;
    }
};
