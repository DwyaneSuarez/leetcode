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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        int len = 0;
        ListNode *p = head;
        while (p) {
            ++len;
            p = p->next;
        }
        ListNode node(0);
        node.next = head;
        ListNode *l;
        ListNode *r;
        for (int i = 1; i <= len; i *= 2) {
            ListNode *tail = &node;
            ListNode *cur = tail->next;
            while (cur) {
                l = cur;
                r = split(l, i);
                cur = split(r, i);
                auto m = merge(l, r);
                tail->next = m.first;
                tail = m.second;
            }
        }
        return node.next;
    }
private:
    ListNode* split(ListNode *p, int n) {
        while (--n && p)
            p = p->next;
        ListNode *rest = p ? p->next : nullptr;
        if (p)
            p->next = nullptr;
        return rest;
    }
    pair<ListNode*, ListNode*> merge(ListNode *p1, ListNode *p2) {
        ListNode node(0); // automated release
        ListNode *cur = &node;
        while (p1 && p2) {
            if (p1->val > p2->val)
                swap(p1, p2);
            cur->next = p1;
            p1 = p1->next;
            cur = cur->next;
        }
        cur->next = p1 ? p1 : p2;
        while (cur->next)
            cur = cur->next;
        return {node.next, cur};
    }
};
