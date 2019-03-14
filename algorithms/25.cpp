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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans = head;
        for (int i = 1; i < k; i++) {
            if (ans == NULL) {
                ans = head;
                break;
            }
            ans = ans->next;
        }
        if (ans == NULL)
            ans = head;
        ListNode* p = head;
        ListNode* last = NULL;
        while (p) {
            bool done = false;
            ListNode* tmp = p;
            for (int i = 0; i < k; i++) {
                if (tmp == NULL) {
                    done = true;
                    break;
                }
                tmp = tmp->next;
            }
            if (done)
                break;
            tmp = p->next;
            ListNode* prev = p;
            for (int i = 1; i < k; i++) {
                prev->next = tmp->next;
                tmp->next = p;
                p = tmp;
                tmp = prev->next;
            }
            if (last)
                last->next = p;
            last = prev;
            p = prev->next;
        }
        return ans;
    }
};
