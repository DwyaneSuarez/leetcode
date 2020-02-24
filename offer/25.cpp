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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *ret = NULL;
        ListNode *cur = NULL;
        while (p && q) {
            if (p->val >= q->val)
                swap(p, q);
            if (!ret)
                ret = p;
            if (!cur)
                cur = p;
            else
                cur->next = p, cur = cur->next;
            p = p->next;
        }
        if (cur)
            cur->next = p ? p : q;
        else
            ret = p ? p : q, cur = p ? p : q;
        return ret;
    }
};