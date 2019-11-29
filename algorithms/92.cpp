/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNodeint( x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *vir = new ListNode(0);
        vir->next = head;
        ListNode* start = head;
        ListNode* spre = vir;
        for (int i = 0; i < m - 1; ++i)
            start = start->next, spre = spre->next;
        ListNode* cur = start;
        ListNode* pre = cur;
        for (int i = 0; i < n - m; ++i) {
            cur = cur->next;
            spre->next = cur;
            pre->next = cur->next;
            cur->next = start;
            start = cur;
            cur = pre;
        }
        ListNode* ret = vir->next;
        delete vir;
        return ret;
    }
};
