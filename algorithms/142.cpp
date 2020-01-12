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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
            if (slow == fast && slow) {
                ListNode *p1 = head;
                while (p1 != slow) {
                    p1 = p1->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
