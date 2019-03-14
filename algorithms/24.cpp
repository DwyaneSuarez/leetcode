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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* ans = head->next ? head->next : head;
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* pre = NULL;
        while (p != NULL && q != NULL) {
            ListNode* temp = q->next;
            if (pre)
                pre->next = q;
            q->next = p;
            p->next = temp;
            pre = p;
            p = temp;
            if (p)
                q = temp->next;
        }
        return ans;
    }
};
